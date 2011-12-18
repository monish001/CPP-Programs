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

class XlsToCmdReadVertically
{
	public static void main(String[] args) throws NullPointerException, java.io.FileNotFoundException, java.io.IOException
	{
		if(args.length < 4)
		{
			System.out.println("Give command line arguments: xlsFileName Degree Year RowContaingSectionsName");
			System.exit(0);
		}
		String degree = args[1];
		short year = (short)Integer.parseInt(args[2]);
		short RowContaingSectionsName = (short)Integer.parseInt(args[3]);
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
		{
			mergeRange[i] = sheet.getMergedRegion(i);
		}
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
			break breakHere;
		}
//Read section names
		sectionsNames = new String[noOfSections];
		breakOut:
		for(Row rr : sheet)
		{
			if(rr.getRowNum() <6)
				continue;
			for(Cell cc : rr)
			{
				if(cc.getColumnIndex()<2)
					continue;
				sectionsNames[cc.getColumnIndex() - 2] = cc.getRichStringCellValue().getString();
			}
			break breakOut;
		}
//Cells Traversal:
		for(Iterator<Row> rit = sheet.rowIterator(); rit.hasNext();)
		{
			for(int coun =0; coun<6; coun++)
				session[coun] = null;
			//session[DAY] = ;
			//session[PERIOD] = ;
			int startingColIndexForRow1=-1;
			CellRangeAddress currCellRange = null;
			boolean classForSingleSection = false;//initialized by row1
			boolean cellsFromRow2AreInGroupOf2WithEachOther = false;//initialized by row2//true means its a lab
//Row 1
			Row row = rit.next();
			System.out.println(1+row.getRowNum()+"------------------------------");
			if(row.getRowNum() < 6)
				continue;//rows before that one containing list of section names need not to be traversed.
		//System.out.println("myRorNo : "+row);
			for(Cell cell : row)
			{
				if(cell.getColumnIndex() < 4)
					continue;
				else if((cell.getColumnIndex() > 5))
					break;
				if(cell.getColumnIndex() % 2 ==0)// == 4)
				{
					startingColIndexForRow1 = -1;
					currCellRange = null;
					currCellRange = findMergedRange(row.getRowNum(), cell.getColumnIndex());//check the mergedCellArea to which this cell belongs.
					if(currCellRange != null)
					{
						if(currCellRange.getFirstColumn() == cell.getColumnIndex() &&
						currCellRange.getLastColumn() == 1+cell.getColumnIndex())//check here if this class is for single section. If yes, set the variable to true
							classForSingleSection = true;
						else
							startingColIndexForRow1 = currCellRange.getFirstColumn();
						//System.out.println("classForSingleSection: "+classForSingleSection+"\nstartingColIndexForRow1: "+startingColIndexForRow1);
					}
				}
				CellReference cellRef = new CellReference(row.getRowNum(), cell.getColumnIndex());
				switch(cell.getCellType())
				{
					case Cell.CELL_TYPE_STRING:
						if(!((cell.getRichStringCellValue().getString()).equals("")))
							session[COURSE] = cell.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
						break;
					default://check if this cell is merged? if yes, get course name
						if(currCellRange != null//makes sure that the current cell is in merged region and not single
						&& currCellRange.getNumberOfCells()>2//not just for a single section
						&& currCellRange.getFirstColumn() != cell.getColumnIndex())//it is not the starting cell of the merged area
							for(Row r_ : sheet){//read contents of cell(row.getRowNum(), currCellRange.getFirstColumn())
								if(r_.getRowNum() != row.getRowNum())	continue;
								for(Cell c_ : r_)
								{
									if(c_.getColumnIndex() != currCellRange.getFirstColumn())	continue;
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
			currCellRange = null;
//Row 2
			row = rit.next();
			for(Cell cell : row)
			{
				if(cell.getColumnIndex() < 4)
					continue;
				else if((cell.getColumnIndex() > 5))
					break;
				//set variable cellsFromRow2AreInGroupOf2WithEachOther here.
				if(cell.getColumnIndex()%2 == 0 /*== 4*/ && classForSingleSection == true)//only set if classForSingleSection is true
				{
					currCellRange = findMergedRange(row.getRowNum(), cell.getColumnIndex());//check the mergedCellArea to which this cell belongs.
					if(currCellRange != null)	
						if(currCellRange.getFirstColumn() == cell.getColumnIndex() &&
						currCellRange.getLastColumn() == 1+cell.getColumnIndex())
							cellsFromRow2AreInGroupOf2WithEachOther = true;//check and initialize cellsFromRow2AreInGroupOf2WithEachOther
				}
				CellReference cellRef = new CellReference(row.getRowNum(), cell.getColumnIndex());
				switch(cell.getCellType())
				{
					case Cell.CELL_TYPE_STRING:
						if(!((cell.getRichStringCellValue().getString()).equals("")))
							if(cell.getColumnIndex()%2 == 0)//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
							{
								session[ROOM] = cell.getRichStringCellValue().getString();
								if(session[ROOM] != null)
									break;
							}
							else
							{
								session[TEACHER] = cell.getRichStringCellValue().getString();
								break;
							}
					default://comes here in case of lab or multi-section class
						//System.out.println("default:");
						//if(classForSingleSection == false && currCellRange != null)
						//read from row.getRowNum(), startingColIndexForRow1
						for(Row r_ : sheet)
						{
							if(r_.getRowNum() != row.getRowNum())	continue;
							for(Cell c_ : r_)
							{
								if(c_.getColumnIndex() != startingColIndexForRow1)	continue;
								if(!((c_.getRichStringCellValue().getString()).equals("")))
								if(cell.getColumnIndex()%2 == 0)//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());
									session[ROOM] = c_.getRichStringCellValue().getString();
								//else
									//session[TEACHER] = c_.getRichStringCellValue().getString();
							}
						}
				}//switch
			}//for cell
			if(!classForSingleSection)
			{
				if(session[COURSE] != null)//if(!((session[COURSE]+session[ROOM]+session[TEACHER]).equals("")))
					System.out.println("1."+session[COURSE]+"\n2."+session[ROOM]+"\n3."+session[TEACHER]);
				continue;}
			if(!cellsFromRow2AreInGroupOf2WithEachOther){
				if(session[COURSE] != null)//if(!((session[COURSE]+session[ROOM]+session[TEACHER]).equals("")))
					System.out.println("1."+session[COURSE]+"\n2."+session[ROOM]+"\n3."+session[TEACHER]);
				continue;//if cells from row 2 are not in group of 2 with each other then continue
			//if the Row3 and Row4 code is run, it means there is a lab.
			}
			currCellRange = null;
//Row3
			row = rit.next();
			for(Cell cell : row)
			{
				if(cell.getColumnIndex() <= 3)
					continue;
				else if((cell.getColumnIndex() >= 6))
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
			currCellRange = null;
//Row4
			row = rit.next();
			for(Cell cell : row)
			{
				if(cell.getColumnIndex() <= 3)
					continue;
				else if((cell.getColumnIndex() >= 6))
					break;
				CellReference cellRef = new CellReference(row.getRowNum(), cell.getColumnIndex());
				switch(cell.getCellType())
				{
					case Cell.CELL_TYPE_STRING:
						if(!((cell.getRichStringCellValue().getString()).equals("")))
							session[TEACHER] = cell.getRichStringCellValue().getString();//System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
						
						break;
					//default:
						//System.out.println(" ");//("<In Default>");
				}//switch
				break;
			}//for cell
			if(session[COURSE] != null)//if(!((session[COURSE]+session[ROOM]+session[TEACHER]).equals("")))
				System.out.println("1."+session[COURSE]+"\n2."+session[ROOM]+"\n3."+session[TEACHER]);
		}//for row
	}//main
	static CellRangeAddress findMergedRange(int rowInd, int colInd)//check if rowInd,colInd isinany mergeRange
	{
		CellRangeAddress cellRange = null;
		for(int i=0; i<noOfMR; ++i)
			if(mergeRange[i].isInRange(rowInd, colInd))
				return mergeRange[i];
		return null;
	}
	static String[] sectionsNames;
	static int noOfSections = 0;
	static int COURSE=0, ROOM=1, TEACHER=2, SECTION=3, DAY=4, PERIOD=5;
	static String[] session = new String[6];
	static int noOfMR;
	static CellRangeAddress[] mergeRange;
}//class