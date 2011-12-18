import java.sql.*;
import java.util.*;
import java.io.*;

class jdbcconn
{
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
		return(DriverManager.getConnection("jdbc:oracle:thin:@172.31.5.22:1521:splcsed","Saloni","dswdt"));////Get a Connection object
	}

	public static void main(String args[]) throws SQLException,IOException
	{
		jdbcconn c=new Jdbcconn();
		//String qry= new String();
		Connection con=c.conn();//Get a Connection object
		Scanner in=new Scanner(System.in);
		Statement stmt = con.createStatement();//Get a Statement object
        	ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
		String qry=new String("SELECT empno,ename,job,mgr,to_char(hiredate,'dd/mm/yyyy'),sal,comm,deptno FROM EMP");//Execute queries and/or updates
		rset=stmt.executeQuery(qry);
		System.out.println("EMPNO\tENAME\tJOB\tMGR\tHIREDATE\tSAL\tCOMM\tDEPTNO");
		while(rset.next())
		{
			System.out.println(rset.getInt(1)+"\t"+rset.getString(2)+"\t"+rset.getString(3)+"\t"+rset.getInt(4)+"\t"+rset.getString(5)+"\t"+rset.getInt(6)+"\t"+rset.getInt(7)+"\t"+rset.getInt(8)+"\n");
		}
	}
}
