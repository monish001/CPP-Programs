//XlsToCmdReadVertically1.java: working but no merge cell detection implementation yet.

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
		for(Row row : sheet){
			if(row.getRowNum() < 6)
				continue;//rows before that one containing list of section names need not to be traversed.
		//System.out.println("myRorNo : "+row);
			for(Cell cell : row)
			{
				if(!(cell.getColumnIndex() > 3 && cell.getColumnIndex() < 6))
					continue;
				CellReference cellRef = new CellReference(row.getRowNum(), cell.getColumnIndex());
				//System.out.print("\n"+cellRef.formatAsString());
				//System.out.print(" - ");
				
				switch(cell.getCellType())
				{
					case Cell.CELL_TYPE_STRING:
						if(!((cell.getRichStringCellValue().getString()).equals("")))
							System.out.println(cellRef.formatAsString()+" - <In String> "+cell.getRichStringCellValue().getString());
						break;
					case Cell.CELL_TYPE_NUMERIC:
/*						if(DateUtil.isCellDateFormatted(cell))
							if(!((cell.getDateCellValue()).equals("")))
								System.out.println(cell.getDateCellValue());
						else*/
						if(!((((Double)(cell.getNumericCellValue())).toString()).equals("")))
							System.out.println(cellRef.formatAsString()+" - <In Numeric>"+cell.getNumericCellValue());
						break;
/*					case Cell.CELL_TYPE_BOOLEAN:
						if(!(((String)(cell.getBooleanCellValue())).equals("")))
							System.out.println(cell.getBooleanCellValue());
						break;*/
/*					case Cell.CELL_TYPE_FORMULA:
						if(!((cell.getCellFormula()).equals("")))
							System.out.println(cell.getCellFormula());
						break;
					default:
						System.out.println("<In Default>");*/
				}
			}
		}
	}
}