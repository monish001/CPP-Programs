////TT1.java : has just a 'Back button' to go back to page1 and hide page2.
//TT2.java
import java.sql.*;
//import javax.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class TT{
	String tName;
	TT(String str)
	{
		this.tName = str;
	}
	public static void main(String[] args){
		//myFrame frame;
		EventQueue.invokeLater(new Runnable()
		{
            public void run(){
                   myFrame frame=new myFrame(tName);
                    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    frame.setVisible(true);
            }
        });
	}
}
class myFrame extends JFrame{
/*	public static String[] initialOptions( String tname )
		{
		int noOfRows=0;
		qry=new String("select count(*) from "+tname);//Execute queries and/or updates
		String[] CBoxOptions = null;
		try
		{
			rset=stmt.executeQuery(qry);
			while(rset.next())
			{
				noOfRows = rset.getInt(1);
			}
			CBoxOptions = new String[noOfRows];
			qry=new String("select * from "+tname);//Execute queries and/or updates
			rset=stmt.executeQuery(qry);
			for(int count=0; rset.next(); count++)
			{
				CBoxOptions[count] = rset.getString(1);
			}
		}
		catch(Exception e)
		{
			System.out.println("2.)Error in InitialOptions "+e.toString());
		}			
		return (CBoxOptions);
	}*/
    myFrame(String tName){
        setTitle("Administrator Screen");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		setResizable(false); 
		JdbcConnection myCon = new JdbcConnection();
		try
		{
			Connection con = myCon.conn();//Get a Connection object
			stmt = con.createStatement();//Get a Statement object				
		}
		catch(SQLException e)
		{
			System.out.println("1.)Error in con or stmt "+e.toString());
		}		
		Scanner in = new Scanner(System.in);

		JPanel TTPanel = new JPanel(); //New Panel to be addded to frame
		TTPanel.setLayout(new GridLayout(4,1));
		page1rowTypeA Trow = new page1rowTypeA(TTPanel, "batch", myFrame.initialOptions("batch"), 25);

		page1rowTypeA Crow = new page1rowTypeA(TTPanel, "course", myFrame.initialOptions("course"), 60);

		page1rowTypeA Grow = new page1rowTypeA(TTPanel, "room", myFrame.initialOptions("room"), 95);

		page1rowTypeA Rrow = new page1rowTypeA(TTPanel, "teacher", myFrame.initialOptions("teacher"), 130);
		mainPanel = new JPanel();
		mainPanel.setLayout(new GridLayout(2,1));
		mainPanel.add(TTPanel);
		mainPanel.add(page1rowTypeA.nextPanel);
	    add(mainPanel, BorderLayout.CENTER);//adds mainPanel to the frame
		add(page1rowTypeA.btn_south, BorderLayout.SOUTH);
		add(page1rowTypeA.btnHead, BorderLayout.NORTH);
		//pack();
    }

/*	public static boolean insert(String itemToInsert, String tName)
	{
		qry = ("Insert into "+tName+"(id) values('"+itemToInsert+"')");
		try{
			stmt.executeUpdate(qry);
			return (true);
		}
		catch(SQLException e)
		{
			System.out.println("Error in static insert() "+e.toString());
			return (false);
		}		
	}
	public static boolean delete(String itemToDelete, String tName)
	{
		qry = ("delete from "+tName+" where id = '"+itemToDelete+"'");
		try
		{
			stmt.executeUpdate(qry);
			return (true);
		}
		catch(SQLException e)
		{
			System.out.println("Error in static delete() "+e.toString());
			return (false);
		}		
	}
	public static boolean update(String oldItem, String newItem, String tName)
	{
		qry = ("Update "+tName+" set id = '"+newItem+"' where id = '"+oldItem+"'");
		try
		{
			stmt.executeUpdate(qry);
			return (true);
		}
		catch(SQLException e)
		{
			System.out.println("Error in static update() "+e.toString());
			return (false);
		}		
	}*/
	JPanel mainPanel;
	static Statement stmt;
	static ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
	static String qry;
}