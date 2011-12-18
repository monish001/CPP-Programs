////TT1.java : has a 'Back button' only to go back to page1 and hide page2.
//frame2.java
import java.sql.*;
//import javax.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class frame2page extends JFrame{
	public static void main(String args[])
	{
		new frame2page("teacher");
	}
    frame2page(String tName){
		innerBox.tName = tName;
        setTitle("Administrator Screen");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		setResizable(false); 
		/*FOR CONNECTION:			FOR CONNECTION:			FOR CONNECTION:
		JdbcConnection myCon = new JdbcConnection();
		try
		{
			Connection con = myCon.conn();//Get a Connection object
			stmt = con.createStatement();//Get a Statement object				
		}
		catch(SQLException e)
		{
			System.out.println("1.)Error in con or stmt "+e.toString());
		}*/		
		
		add(page1rowTypeA.btnHead, BorderLayout.NORTH);
		add(page1rowTypeA.btn_south, BorderLayout.SOUTH);
		JLabel northLabel = new JLabel(tName+"s:");
		JComboBox northCBox = new JComboBox();//myFrame.initialOptions(tname, "id"));
		JPanel row1CenterPanel = new JPanel();
		row1CenterPanel.add(northLabel);
		row1CenterPanel.add(northCBox);
		JPanel daysCenterPanel = new JPanel();
		daysCenterPanel.setLayout(new GridLayout(5,9));
		for(int count=0; count<=5*9; count++)
			daysCenterPanel.add(new innerBox().getPanel());
		JPanel centerPanel = new JPanel();
		centerPanel.add(row1CenterPanel);
		centerPanel.add(daysCenterPanel);
}

	//JPanel mainPanel;
	static Statement stmt;
	static ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
	static String qry;
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
}
class innerBox
{
	innerBox()
	{
		System.out.println("In innerBox with day and period ="+day+" "+period);
		panel = new JPanel();
		panel.add(new JButton(day+" "+period));
	}
	JPanel getPanel(){
		return (this.panel);
	}
	JPanel panel;
	static int day=0;
	static int period=0;
	static String tName;
	static
	{
		if(period==9)
		{
			day++;
			period=1;
		}
		else
			period++;
	}
}