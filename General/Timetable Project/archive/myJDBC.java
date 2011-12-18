import java.io.*;
import java.util.*;
import javax.sql.*;
import java.sql.*;
public class myJDBC{
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
		return(DriverManager.getConnection("jdbc:oracle:thin:@127.0.0.1:1521:USERS","monish001","oracle"));////Get a Connection object
	}

	public static void main(String args[]) throws SQLException,IOException
	{
		JdbcConnection c=new JdbcConnection();
		//String qry= new String();
		Connection con=c.conn();//Get a Connection object
		Scanner in=new Scanner(System.in);
		Statement stmt = con.createStatement();//Get a Statement object
        	ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
		String qry=new String("SELECT * FROM TAB");//("SELECT empno,ename,job,mgr,to_char(hiredate,'dd/mm/yyyy'),sal,comm,deptno FROM EMP");//Execute queries and/or updates
		rset=stmt.executeQuery(qry);
		System.out.println("TNAME\tTABTYPE\tCLUSTERID");
		while(rset.next())
		{
			System.out.println(rset.getString(30)+"\t"+rset.getString(7)+"\t"+rset.getInt(1)+"  \n");
		}
	}
}
