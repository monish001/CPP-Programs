import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
public class DatabaseOperations{
/*	public static void main(String[] args)
	{
			JdbcConnection myCon = new JdbcConnection();
			Connection con = myCon.conn();//Get a Connection object
			Statement stmt = con.createStatement();//Get a Statement object
			stmt.executeUpdate("insert into teacher(id) values('hero')");

	}
*/
    DatabaseOperations(){
		try
		{
			JdbcConnection myCon = new JdbcConnection();
			Connection con = myCon.conn();//Get a Connection object
			stmt = con.createStatement();//Get a Statement object
		}
		catch(Exception e)
		{
			System.out.println("1.)Error in con or stmt "+e.toString());
		}
	}
	public static boolean queryRevertsBoolean(String QueryArg)// throws Exception
	{
		try
		{
			if(QueryArg != null && stmt != null);
			//stmt.executeQuery(QueryArg);
		}
		catch(NullPointerException e)	
		{
			System.out.println("myError null pointer in static insert() "+e.toString());
			return (false);
		}		
		return (true);
	}
	public static void main(String[] args)
	{
	  System.out.println(DatabaseOperations.queryRevertsBoolean("insert into teacher(id) values('hero')"));
	}
	static Statement stmt = null;
	static ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
}