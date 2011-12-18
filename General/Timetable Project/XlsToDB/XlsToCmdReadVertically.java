//SQL suggestions: Do trim with space.
//XlsToCmdReadVertically1.java: working but no merge cell detection implementation yet.
//XlsToCmdReadVertically2.java: CellRangeAddress[] made and initializes
								//but still no merge cell detection implementation.
//XlsToCmdReadVertically3.java: section-wise reading of classes is done.  working.
								//fair implementation for lab detection.
								//but doesnt read course name if there is a class for 1+ sections
//XlsToCmdReadVertically4.java: //now reads course name also.
								//No implementation of str[3] (course, room, teacher) yet.
//XlsToCmdReadVertically5.java: //implementation of session[3] (course, room, teacher) done.
								//printing values only from session[3] array 
//XlsToCmdReadVertically6.java: //Split all the merge areas which done have any content
								//pending: detecting day and period
								//pending: implementation to read the sessions of all the sections
//XlsToCmdReadVertically7.java: //structure ready for:(but not implemented yet)
								//1.extending array session[3] to session[6] to further accomodate section, day, period
								//2.day and period
//XlsToCmdReadVertically8.java: //2 points mentioned above are implemented.
								//support for 2hr tuts needed in which eg. cells have:1.US001, 2.T, 3.-,-, 4.room,teacher
								//pending: support for labs having eg. cells: 1.EC001, 2.-, 3.LAB, 4.teacher
								//pending: 3 hr lab must contain 6 cells that are merged and 4th one must contain 'LAB'
//XlsToCmdReadVertically9.java: //database implemented.
import org.apache.poi.poifs.filesystem.POIFSFileSystem;
import org.apache.poi.ss.util.CellRangeAddress;
import java.util.Iterator;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.ss.util.CellReference;
import org.apache.poi.ss.usermodel.DateUtil;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import java.io.FileInputStream;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

class XlsToCmdReadVertically
{
	public static void main(String[] args) throws NullPointerException, java.io.FileNotFoundException, java.io.IOException
	{
		new insertIntoDB();
		if(args.length < 4)
		{
			System.out.println("Give command line arguments: xlsFileName Degree Year RowContaingSectionsNames");
			System.exit(0);
		}
		String degree = args[1];
		short year = (short)Integer.parseInt(args[2]);
		short RowContaingSectionsNames = (short)Integer.parseInt(args[3]);
		InputStream inp = new FileInputStream(args[0]);
		HSSFWorkbook wb = new HSSFWorkbook(new POIFSFileSystem(inp));
		HSSFSheet sheet = wb.getSheetAt(0);
		noOfMR = sheet.getNumMergedRegions();
		//System.out.println("no of MR is "+ noOfMR);
//initializes mergeRanges[] and split all the merge areas which dont have any content:
		for(int i=0; i<noOfMR; ++i)
		{
			CellRangeAddress MR = null;
			MR = sheet.getMergedRegion(i);
			if(MR == null)
				continue;//System.out.println("MR is null");// 
			String str = null;
			int rowMR = MR.getFirstRow();
			int colMR = MR.getFirstColumn();
			for(Row r_ : sheet)
			{//read MR.getFirstColumn(), MR.getFirstRow()
				if(r_.getRowNum() != rowMR)
				continue;
				for(Cell c_ : r_)
				{
					if(c_.getColumnIndex() != colMR)
					continue;
					switch(c_.getCellType())
					{
						case Cell.CELL_TYPE_STRING:
							if(!((c_.getRichStringCellValue().getString()).equals("")))
								str = c_.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
							break;
						case Cell.CELL_TYPE_NUMERIC:
							if(!((((Double)(c_.getNumericCellValue())).toString()).equals("")))
								str = Double.toString(c_.getNumericCellValue());
							break;
						default:
							str = null;//System.out.println(" ");//("<In Default>");
					}//switch
				}//cell
			}//row
			if(str == null)//read MR.getFirstColumn(), MR.getFirstRow(), if contents == null, then remove merged region.
				sheet.removeMergedRegion(i);
		}
		noOfMR = sheet.getNumMergedRegions();
		mergeRange = new CellRangeAddress[noOfMR];
//initializes mergeRanges[]:
		for(int i=0; i<noOfMR; ++i)
			mergeRange[i] = sheet.getMergedRegion(i);
//count and initialize noOfSections
		breakHere:
		for(Row rr : sheet)
		{
			if(rr.getRowNum() <6)
				continue;
			int maxCellInd = -1;
			for(Cell cc : rr)
				maxCellInd = /*index*/cc.getColumnIndex();
			noOfSections = (1 + maxCellInd) - 2/*day period*/;
			noOfSections /=2; //each section consumes 2 columns
			break breakHere;
		}
//Read section names
		sectionsNames = new String[noOfSections];
		breakOut:
		for(Row rr : sheet)
		{
			if(rr.getRowNum() <(6-1))
				continue;
			for(Cell cc : rr)
			{
				if(cc.getColumnIndex()<2 || cc.getColumnIndex()%2 == 1)
					continue;
				sectionsNames[(cc.getColumnIndex() - 2)/2] = cc.getRichStringCellValue().getString();
			}
			break breakOut;
		}
/*output section names
		for(int countt=0; countt<noOfSections; countt++)
			System.out.println(sectionsNames[countt]);*/
//choose section:
		for(int sec=0; sec<noOfSections; sec++)
		{
//Cells Traversal for the choosen section:
			for(Iterator<Row> rit = sheet.rowIterator(); rit.hasNext();)
			{
//for each session (means class/tut/lab)
				int lastColIndexForRow1=-1;
				int startingColIndexForRow1=-1;
				CellRangeAddress currCellRange = null;
				boolean classForSingleSection = false;//initialized by row1
				boolean cellsFromRow2AreInGroupOf2WithEachOther = false;//initialized by row2//true means its a lab
//Row 1
				if(!(rit.hasNext()))
					continue;
				Row row = rit.next();
				System.out.println(1+row.getRowNum()+"------------------------------");
				if(row.getRowNum() < RowContaingSectionsNames)
					continue;//rows before that one containing list of section names need not to be traversed.
			//System.out.println("myRorNo : "+row);
				for(int coun =0; coun<3; coun++)
					session[coun] = null;
				session[SECTION] = sectionsNames[sec];
				switch(((row.getRowNum() - 6)/2)/10)
					{
						case 0: session[DAY] = "Mon";	break;
						case 1: session[DAY] = "Tue";	break;
						case 2: session[DAY] = "Wed";	break;
						case 3: session[DAY] = "Thu";	break;
						case 4: session[DAY] = "Fri";	break;
						//default: session[DAY] = "Sun";
					}
				session[PERIOD] = Integer.toString(((row.getRowNum() - 6)/2)%10 + 1);
				for(Cell cell : row)
				{
//Only allow if colNo satisfies that of the section chosen above:
					if(cell.getColumnIndex() < sec*2+2)//4)//sec*2+2
						continue;
					//else if(cell.getColumnIndex() > sec*2+2)//5))
						//break;
//If it is 1st column, then do...
					//if(cell.getColumnIndex() % 2 ==0)// == 4)
					{
						lastColIndexForRow1=-1;
						startingColIndexForRow1 = -1;
						currCellRange = null;
						currCellRange = findMergedRange(row.getRowNum(), cell.getColumnIndex());//check the mergedCellArea to which this cell belongs.
						if(currCellRange != null)
						{
							if(currCellRange.getFirstColumn() == cell.getColumnIndex() &&
							currCellRange.getLastColumn() == 1+cell.getColumnIndex())//check here if this class is for single section. If yes, set the variable to true
								classForSingleSection = true;
							startingColIndexForRow1 = currCellRange.getFirstColumn();
							lastColIndexForRow1 = currCellRange.getLastColumn();
							//System.out.println("classForSingleSection: "+classForSingleSection+"\nstartingColIndexForRow1: "+startingColIndexForRow1);
						}
					}
					//CellReference cellRef = new CellReference(row.getRowNum(), cell.getColumnIndex());
					switch(cell.getCellType())
					{
						case Cell.CELL_TYPE_STRING://if this cell is first in merged area, then do this:
							if(!((cell.getRichStringCellValue().getString()).equals("")))
								session[COURSE] = cell.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
							break;
						default://check if this cell is merged? if yes, get course name
							if(currCellRange != null//makes sure that the current cell is in merged region and not single
							//&& currCellRange.getNumberOfCells()>2//not just for a single section
							&& currCellRange.getFirstColumn() != cell.getColumnIndex())//it is not the starting cell of the merged area
								for(Row r_ : sheet){//read contents of cell(row.getRowNum(), currCellRange.getFirstColumn())
									if(r_.getRowNum() != row.getRowNum())	continue;
									for(Cell c_ : r_)
									{
										if(c_.getColumnIndex() != currCellRange.getFirstColumn())
											continue;
										if(!((c_.getRichStringCellValue().getString()).equals("")))
											session[COURSE] = c_.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+c_.getRichStringCellValue().getString());
										else
											session[COURSE] = null;//System.out.println("<Free Period>");//("<In Default>");
									}
								}
							else
								session[COURSE] = null;//System.out.println("<Free Period>");//("<In Default>");
					}//switch
					break;
				}//for cell
//Row 2:
				currCellRange = null;
				if(!(rit.hasNext()))
					continue;
				row = rit.next();
				for(Cell cell : row)
				{
//Only allow traversal of cells for 2 specific cols which corresponds to the chosen section.
					if(cell.getColumnIndex() < sec*2+2)//4)//sec*2+2
						continue;
					else if(cell.getColumnIndex() > sec*2+3)//5))
						break;
//set variable cellsFromRow2AreInGroupOf2WithEachOther here.//=true means it's a lab or a two hour tut.
					if(cell.getColumnIndex()%2 == 0 /*== 4*/ && classForSingleSection == true)//only set if classForSingleSection is true
					{
						currCellRange = findMergedRange(row.getRowNum(), cell.getColumnIndex());//check the mergedCellArea to which this cell belongs.
						if(currCellRange != null
							&& currCellRange.getFirstColumn() == cell.getColumnIndex()
							&& currCellRange.getLastColumn() == 1+cell.getColumnIndex())
								cellsFromRow2AreInGroupOf2WithEachOther = true;//check and initialize cellsFromRow2AreInGroupOf2WithEachOther
					}
					{
						if(cellsFromRow2AreInGroupOf2WithEachOther == true)//lab or two hr tut. 2 row merged of 2 cells
						{
							switch(cell.getCellType())
							{
								case Cell.CELL_TYPE_STRING:
									session[ROOM] = cell.getRichStringCellValue().getString();
									break;
								default:
									System.out.println("in default asdfy");
									session[ROOM] = "";
							}
							break;
						}
						else if(classForSingleSection == true)//tut for 1 section
						{
							if(cell.getColumnIndex()%2 == 0)//left
							{
								session[ROOM] = cell.getRichStringCellValue().getString();
							}
							else//right
							{
								session[TEACHER] = cell.getRichStringCellValue().getString();
							}
						}
						else//lec for multiple sections
						{
							if(cell.getColumnIndex()%2 == 0)//left
							{
								for(Row r_: sheet)
								{
									if(r_.getRowNum() != row.getRowNum())
										continue;
									for(Cell c_ : r_)
									{
										if(c_.getColumnIndex() != startingColIndexForRow1)
											continue;
										//if(!((c_.getRichStringCellValue().getString()).equals("")))
										session[ROOM] = c_.getRichStringCellValue().getString();
									}
								}
							}
							else//right
							{
								for(Row r_: sheet)
								{
									if(r_.getRowNum() != row.getRowNum())
										continue;
									for(Cell c_ : r_)
									{
										if(c_.getColumnIndex() != lastColIndexForRow1)
											continue;
										//System.out.println("I am here 277");
										//if(!((c_.getRichStringCellValue().getString()).equals("")))
										session[TEACHER] = c_.getRichStringCellValue().getString();
									}
								}
							}
						}
					}
				}//for cell
				if(!classForSingleSection)
				{
					try
					{
						if(session[COURSE] != null)//if(!((session[COURSE]+session[ROOM]+session[TEACHER]).equals("")))
						{
							insertIntoDB.insert(session);
							//System.out.println("Cour."+session[COURSE]+"\nRoom."+session[ROOM]+"\nTeac."+session[TEACHER]+
								//"\nSect."+session[SECTION]+"\nDay ."+session[DAY]+"\nPeri."+session[PERIOD]);
						}
					}
					catch(SQLException e){System.out.println(e.toString());}
					continue;
				}
				if(!cellsFromRow2AreInGroupOf2WithEachOther){
					try
					{
						if(session[COURSE] != null)//if(!((session[COURSE]+session[ROOM]+session[TEACHER]).equals("")))
						{
							insertIntoDB.insert(session);
							//System.out.println("Cour."+session[COURSE]+"\nRoom."+session[ROOM]+"\nTeac."+session[TEACHER]+
								//"\nSect."+session[SECTION]+"\nDay ."+session[DAY]+"\nPeri."+session[PERIOD]);
						}
					}
					catch(Exception e){System.out.println(e.toString());}
					continue;//if cells from row 2 are not in group of 2 with each other then continue
				//if the Row3 and Row4 code is run, it means there is a lab.
				}
//Row3
				if(!(rit.hasNext()))
					continue;
				row = rit.next();
				for(Cell cell : row)
				{
					if(cell.getColumnIndex() < sec*2+2)
						continue;
					else if((cell.getColumnIndex() > sec*2+3))
						break;
					CellReference cellRef = new CellReference(row.getRowNum(), cell.getColumnIndex());
					switch(cell.getCellType())
					{
						case Cell.CELL_TYPE_STRING:
							if(!((cell.getRichStringCellValue().getString()).equals("")))
								session[ROOM] = session[ROOM] + " " + cell.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
							break;
						//default:
							//System.out.println(" ");//("<In Default>");
					}//switch
					break;
				}//for cell
//Row4
				if(!(rit.hasNext()))
					continue;
				row = rit.next();
				boolean flag3hrLab = false;
				for(Cell cell : row)
				{
					if(cell.getColumnIndex() < sec*2+2)
						continue;
					else if((cell.getColumnIndex() > sec*2+3))
						break;
//check if this(4th row is merged for two cells? if yes, then lab else 2 hr tut)
					
					CellRangeAddress abc = null;
					abc = findMergedRange(row.getRowNum(), cell.getColumnIndex());
					if(cell.getColumnIndex()%2 == 0)
					{//left cell	
						isItTut = false;
						if(abc != null
							&& abc.getFirstColumn() == cell.getColumnIndex()
							&& abc.getLastColumn() == 1+cell.getColumnIndex())
							isItTut = false;
						else
							isItTut = true;
					}
					//System.out.println("tut?"+isItTut);
					if(isItTut == false)//if lab
					{
						switch(cell.getCellType())
						{
							case Cell.CELL_TYPE_STRING:
								if(!((cell.getRichStringCellValue().getString()).equals("")))
									session[TEACHER] = cell.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
								break;
						}//switch
						break;
					}
					else//if tut
					{
						if(cell.getColumnIndex()%2 == 0)
						{//left
							switch(cell.getCellType())
							{
								case Cell.CELL_TYPE_STRING:
									if(!((cell.getRichStringCellValue().getString()).equals("")))
										session[TEACHER] = cell.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
									break;
							}//switch
						}
						else//right
						{
							session[COURSE] = session[COURSE] + session[ROOM];
							session[ROOM] = session[TEACHER];
							switch(cell.getCellType())
							{
								case Cell.CELL_TYPE_STRING:
									if(!((cell.getRichStringCellValue().getString()).equals("")))
										session[TEACHER] = cell.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
									break;
							}//switch
						}
					}
					if(session[TEACHER] != null
						&& session[TEACHER].equals("LAB"))//3 hr lab
					{
						flag3hrLab = true;
						session[ROOM] = session[ROOM]+session[TEACHER];
						if(!(rit.hasNext()))
							continue;
						row = rit.next();
						if(!(rit.hasNext()))
							continue;
						row = rit.next();
						//read r,c for seesion[TEACHER];
								breakheres:
								for(Row r_: sheet)
								{
									if(r_.getRowNum() != row.getRowNum())
										continue;
									for(Cell c_ : r_)
									{
										if(c_.getColumnIndex() != startingColIndexForRow1)
											continue;
										//System.out.println("I am here 277");
										//if(!((c_.getRichStringCellValue().getString()).equals("")))
										session[TEACHER] = c_.getRichStringCellValue().getString();
											break breakheres;
									}
								}

					}
				}//for cell
				if(session[COURSE] != null && !(session[COURSE].equals("null"))
					&& !(session[COURSE].equals(null))
					&& !(session[COURSE].equals("")))//if(!((session[COURSE]+session[ROOM]+session[TEACHER]).equals("")))
				{
					System.out.println("Cour."+session[COURSE]+"\nRoom."+session[ROOM]+"\nTeac."+session[TEACHER]
						+"\nSect."+session[SECTION]+"\nDay ."+session[DAY]+"\nPeri."+session[PERIOD]);
					System.out.println((row.getRowNum()-((flag3hrLab)?(2):(0)))+"------------------------------");
					System.out.println("Cour."+session[COURSE]+"\nRoom."+session[ROOM]+"\nTeac."+session[TEACHER]
						+"\nSect."+session[SECTION]+"\nDay ."+session[DAY]+"\nPeri."+(1+Integer.parseInt(session[PERIOD])));
					if(flag3hrLab)
					{
						System.out.println(row.getRowNum()+"------------------------------");
						System.out.println("Cour."+session[COURSE]+"\nRoom."+session[ROOM]+"\nTeac."+session[TEACHER]
							+"\nSect."+session[SECTION]+"\nDay ."+session[DAY]+"\nPeri."+(1+Integer.parseInt(session[PERIOD])));
					}
				}
			}//for rows of chosen section
		}//for choosing 1 section
	}//main
	static CellRangeAddress findMergedRange(int rowInd, int colInd)//check if rowInd,colInd isinany mergeRange
	{
		CellRangeAddress cellRange = null;
		for(int i=0; i<noOfMR; ++i)
			if(mergeRange[i].isInRange(rowInd, colInd))
				return mergeRange[i];
		return null;
	}
	static boolean isItTut;
	static String[] sectionsNames;
	static int noOfSections = 0;
	static int COURSE=0, ROOM=1, TEACHER=2, SECTION=3, DAY=4, PERIOD=5;
	static String[] session = new String[6];
	static int noOfMR;
	static CellRangeAddress[] mergeRange;
}//class
class insertIntoDB
{
	insertIntoDB()
	{
		try
		{
			JdbcConnection c = new JdbcConnection();
			Connection con = c.conn();//Get a Connection object
			stmt = con.createStatement();
		}
		catch(SQLException e){System.out.println(e.toString());}
	}
	static void insert(String[] session) throws SQLException
	{
//courses
		String[] coursesList = myFrame.initialOptions("course", "id");
		boolean flag = false;
		if(coursesList.length != 0)
			for(String str : coursesList)
				if(str.equals(session[COURSE]))
				{
					flag = true;
				}
		stmt.executeUpdate("INSERT INTO course VALUES('"+ session[COURSE] +"')");
//batches or sections
		String[] sectionsList = myFrame.initialOptions("batch", "id");
		flag = false;
		for(String str : sectionsList)
			if(str.equals(session[SECTION]))
			{
				flag = true;
			}
		stmt.executeUpdate("INSERT INTO batch VALUES('"+ session[SECTION] +"')");
//teacher
		String[] teachersList = myFrame.initialOptions("teacher", "id");
		flag = false;
		for(String str : teachersList)
			if(str.equals(session[TEACHER]))
			{
				flag = true;
			}
		stmt.executeUpdate("INSERT INTO teacher VALUES('"+ session[TEACHER] +"')");
//rooms
		String[] roomsList = myFrame.initialOptions("room", "id");
		flag = false;
		for(String str : roomsList)
			if(str.equals(session[ROOM]))
			{
				flag = true;
			}
		stmt.executeUpdate("INSERT INTO room VALUES('"+ session[ROOM] +"')");
//TIMETABLE (table tt)
		int day=0;
		if(session[DAY].equals("Mon"))
			day=1;
		else if(session[DAY].equals("Tue"))
			day=2;
		else if(session[DAY].equals("Wed"))
			day=3;
		else if(session[DAY].equals("Thu"))
			day=4;
		else if(session[DAY].equals("Fri"))
			day=5;
		stmt.executeUpdate("INSERT INTO tt(cid, rid, tid, sid, day, period) VALUES('"+session[COURSE]+"', '"+session[ROOM]+"', '"+session[TEACHER]+"', '"+session[SECTION]+"', "+day+", "+session[PERIOD]+")");
		stmt.executeUpdate("commit");
		//con.close();
	}
	static Statement stmt;
	static int COURSE=0, ROOM=1, TEACHER=2, SECTION=3, DAY=4, PERIOD=5;
}