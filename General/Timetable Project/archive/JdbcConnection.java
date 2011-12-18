import java.sql.*;
//import javax.sql.*;
import java.util.*;
import java.io.*;

public class JdbcConnection 
{
	JdbcConnection()
	{

	}
	public Connection conn() throws SQLException//method of class JdbcConnection
	{
	Connection conn;
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");//Load DB-specific JDBC driver
		}
		catch(ClassNotFoundException e)
		{
			System.out.println("Database Driver not found");
			System.out.println(e.toString());
		}
		catch(Exception e)
		{
			System.out.println(e.toString());
		}
                //return(DriverManager.getConnection("jdbc:oracle:thin:@127.0.0.1:1521:XE","SYSTEM","Oracle1"));////Get a Connection object
                return(DriverManager.getConnection("jdbc:oracle:thin:@127.0.0.1:1521:XE","monish001","oracle"));////Get a Connection object
	}
	
	public static void main(String args[]) throws SQLException,IOException
	{
		JdbcConnection c=new JdbcConnection();
		//String qry= new String();
		Connection con=c.conn();//Get a Connection object
		Scanner in=new Scanner(System.in);
		Statement stmt = con.createStatement();//Get a Statement object
        	ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
		String qry=new String("select * from batch");//Execute queries and/or updates
		rset=stmt.executeQuery(qry);
		//System.out.println("Name\tNull?\tType");
		while(rset.next())
		{
			System.out.println(rset.getString(1));
		}
		//close(con);
	}
}
                                                                                                                      
