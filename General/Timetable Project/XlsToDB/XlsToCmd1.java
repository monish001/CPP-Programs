//In next version, Row, Cell,  Sheet will be appened with HSSF

import org.apache.poi.hssf.record.formula.functions.Row;
//import org.apache.poi.hssf.model.Sheet;
//import org.apache.poi.hssf.usermodel.HSSFCell;
import java.io.InputStream;
import org.apache.poi.ss.util.CellReference;
import org.apache.poi.ss.usermodel.DateUtil;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import java.io.FileInputStream;
import org.apache.poi.poifs.filesystem.POIFSFileSystem;

class XlsToCmd
{
	public static void main(String[] args)
	{
		InputStream inp = new FileInputStream("UG-III.xls");
		HSSFWorkbook wb = new HSSFWorkbook(new POIFSFileSystem(inp));
		//ExcelExtractor extractor = new ExcelExtractor(wb);
		
		//extractor.setFormulasNotResults(true);
		//extractor.setIncludeSheetNames(false);
		//String text = extractor.getText();
		Sheet sheet = wb.getSheetAt(0);
		for(Row row : sheet){
			for(Cell cell : row)
			{
				CellReference cellRef = new CellReference(row.getRowNum(), cell.getCellNum());
				System.out.print(cellRef.formatAsString());
				System.out.print(" - ");
				
				switch(cell.getCellType())
				{
					case Cell.CELL_TYPE_STRING:
						System.out.println(cell.getRichStringCellValue().getString());
						break;
					case Cell.CELL_TYPE_NUMERIC:
						if(DateUtil.isCellDateFormatted(cell))
							System.out.println(cell.getDateCellValue());
						else
							System.out.println(cell.getNumericCellValue());
						break;
					case Cell.CELL_TYPE_BOOLEAN:
						System.out.println(cell.getBooleanCellValue());
						break;
					case Cell.CELL_TYPE_FORMULA:
						System.out.println(cell.getCellFormula());
						break;
					default:
						System.out.println();
				}
			}
		}
	}
}