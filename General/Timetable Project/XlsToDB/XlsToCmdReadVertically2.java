//XlsToCmdReadVertically1.java: working but no merge cell detection implementation yet.
//XlsToCmdReadVertically2.java: CellRangeAddress[] made and initializes
								//but still no merge cell detection implementation.

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
		//ExcelExtractor extractor = new ExcelExtractor(wb);
		//extractor.setFormulasNotResults(true);
		//extractor.setIncludeSheetNames(false);
		//String text = extractor.getText();
		HSSFSheet sheet = wb.getSheetAt(0);
		noOfMR = sheet.getNumMergedRegions();
		mergeRange = new CellRangeAddress[noOfMR];
		for(int i=0; i<noOfMR; ++i)//initializes mergeRanges[]
		{
			mergeRange[i] = sheet.getMergedRegion(i);
		}
		//Cells Traversal:
		for(Iterator<Row> rit = sheet.rowIterator(); rit.hasNext();)
		{
			Row row = rit.next();
			if(row.getRowNum() < 6)
				continue;//rows before that one containing list of section names need not to be traversed.
		//System.out.println("myRorNo : "+row);
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
							System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
						break;
					case Cell.CELL_TYPE_NUMERIC:
						if(!((((Double)(cell.getNumericCellValue())).toString()).equals("")))
							System.out.println(cellRef.formatAsString()+" "+cell.getNumericCellValue());//println(cellRef.formatAsString()+" - <In Numeric>"+cell.getNumericCellValue());
						break;
					default:
						System.out.println(" ");//("<In Default>");
				}//switch
			}//for cell
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
							System.out.println(cellRef.formatAsString()+" "+cell.getRichStringCellValue().getString());//"Row: "+row.getRowNum()+" Cell: "+cell.getColumnIndex()+" "+cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
						break;
					case Cell.CELL_TYPE_NUMERIC:
						if(!((((Double)(cell.getNumericCellValue())).toString()).equals("")))
							System.out.println(cellRef.formatAsString()+" "+cell.getNumericCellValue());//println(cellRef.formatAsString()+" - <In Numeric>"+cell.getNumericCellValue());
						break;
					default:
						System.out.println(" ");//("<In Default>");
				}//switch
			}//for cell
		}//for row
	}//main
	CellRangeAddress findMergedRange(int rowInd, int colInd)//check if rowInd,colInd isinany mergeRange
	{
		CellRangeAddress cellRange = null;
		for(int i=0; i<noOfMR; ++i)
			if(mergeRange[i].isInRange(rowInd, colInd))
				return mergeRange[i];
		return null;
	}
	static int noOfMR;
	static CellRangeAddress[] mergeRange;
}//class