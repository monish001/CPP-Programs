import java.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
class DatabaseOperations{
    DatabaseOperations()
	{
		try
		{
			JdbcConnection myCon = new JdbcConnection();
			Connection con = myCon.conn();//Get a Connection object
			stmt = con.createStatement();//Get a Statement object
			System.out.println(myCon.toString());
		}
		catch(SQLException e)	{
			System.out.println("1.)Error in con or stmt "+e.toString());
		}
	}
	public static boolean queryRevertsBoolean(String QueryArg)
	{
		try
		{
			if(QueryArg != null && stmt != null)
			rset = stmt.executeQuery(QueryArg);
			if(rset != null)
			while(rset.next())
			{
				System.out.println("here>>>>>>>>>>>"+rset.getString(1));
			}
		}
		catch(Exception e)	
		{
			System.out.println("myError null pointer in static insert() "+e.toString());
			return (false);		
		}		
		return (true);
	}
	public static void main(String[] args)
	{
	  System.out.println(DatabaseOperations.queryRevertsBoolean("abcselect * from teacherhj"));//("insert into teacher values('monish')"));
	}
	static Statement stmt;
	static ResultSet rset = null;  // = stmt.executeQuery("select max(studentid) from student");
}