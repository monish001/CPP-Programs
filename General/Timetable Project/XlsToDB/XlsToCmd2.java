//XlsToCmd.java
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import java.io.InputStream;
import org.apache.poi.ss.util.CellReference;
import org.apache.poi.ss.usermodel.DateUtil;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import java.io.FileInputStream;
import org.apache.poi.poifs.filesystem.POIFSFileSystem;

class XlsToCmd
{
	public static void main(String[] args) throws java.io.FileNotFoundException, java.io.IOException
	{
		
		if(args.length < 3)
		{
			System.out.println("Give command line arguments: xlsFileName Degree Year");
			System.exit(0);
		}
		InputStream inp = new FileInputStream(args[0]);
		HSSFWorkbook wb = new HSSFWorkbook(new POIFSFileSystem(inp));
		HSSFSheet sheet = wb.getSheetAt(0);
		for(Row row : sheet)
		{
			for(Cell cell : row)
			{
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
						break;
					case Cell.CELL_TYPE_FORMULA:
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