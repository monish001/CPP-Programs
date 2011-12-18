//XlsToCmd.java
//XlsToCmd2.java: working with 1 argument
//XlsToCmd3.java: 3 cmd arguments
//XlsToCmd4.java: iterators used instead of foreach loops
//XlsToCmd5.java: Working backup, prints out the content of any xls sheet. No merge cell detection
				//implementation yet.
//XlsToCmd6.java: output string formatting is refined.
				//RowContaingSectionsName attribute is introduced and reading of cells would be done
				//from this row onwards (eg 7 input value means reading will be done from Row
				//6(0-based))
import org.apache.poi.poifs.filesystem.POIFSFileSystem;
import org.apache.poi.ss.util.CellRangeAddress;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.ss.util.CellReference;
import org.apache.poi.ss.usermodel.DateUtil;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import java.io.FileInputStream;
import java.util.Iterator;
import java.io.InputStream;

class XlsToCmd
{
	public static void main(String[] args) throws java.io.FileNotFoundException, java.io.IOException
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
		for(Iterator<Row> rit = sheet.rowIterator(); rit.hasNext();)
		{
			Row row = rit.next();
			if(row.getRowNum() < RowContaingSectionsName)
				continue;//rows before that one containing list of section names need not to be traversed.
			for(Cell cell : row)
			{
				CellReference cellRef = new CellReference(row.getRowNum(), cell.getColumnIndex());
				//System.out.print("\n"+cellRef.formatAsString());
				//System.out.print(" - ");
				
				switch(cell.getCellType())
				{
					case Cell.CELL_TYPE_STRING:
						if(!((cell.getRichStringCellValue().getString()).equals("")))
							System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
						break;
					case Cell.CELL_TYPE_NUMERIC:
/*						if(DateUtil.isCellDateFormatted(cell))
							if(!((cell.getDateCellValue()).equals("")))
								System.out.println(cell.getDateCellValue());
						else*/
						if(!((((Double)(cell.getNumericCellValue())).toString()).equals("")))
							System.out.println(cellRef.formatAsString()+" "+cell.getNumericCellValue());//println(cellRef.formatAsString()+" - <In Numeric>"+cell.getNumericCellValue());
						break;
/*					case Cell.CELL_TYPE_BOOLEAN:
						if(!(((String)(cell.getBooleanCellValue())).equals("")))
							System.out.println(cell.getBooleanCellValue());
						break;
					case Cell.CELL_TYPE_FORMULA:
						if(!((cell.getCellFormula()).equals("")))
							System.out.println(cell.getCellFormula());
						break;*/
					default:
						System.out.println(" ");//("<In Default>");
				}
			}
		}
		System.out.println(sheet.getNumMergedRegions());
	}
}