////TT1.java : has a 'Back button' only to go back to page1 and hide page2.
//frame2.java
import java.sql.*;
//import javax.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
class myFrame2 extends JFrame{
	public static void main(String args[])
	{
		new myFrame2(args[0]);
	}
	myFrame2()
	{
		this.tableName = tableName;
		setTables();
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
		
	}
    myFrame2(String tableName){
		this();
		btnHead.setEnabled(false);
		btnFoot.setEnabled(false);
		add(btnHead, BorderLayout.NORTH);
		add(btnFoot, BorderLayout.SOUTH);
		JLabel northLabel = new JLabel(tableName+"s:");
		JComboBox northCBox = new JComboBox(myFrame.initialOptions(tableName, "id"));
		JPanel daysCenterPanel = new JPanel();
		northCBox.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				if((!(String)((JComboBox)event.getSource()).getSelectedItem()).equals("-Select-"))
					showTT((String)northCBox.getSelectedItem(), daysCenterPanel);
				else
					btnFoot.setText("Select a "+tableName+" from the list!!");
			}
		});
		JPanel row1CenterPanel = new JPanel();
		row1CenterPanel.setLayout(new GridLayout(1,2));
		row1CenterPanel.add(northLabel);
		row1CenterPanel.add(northCBox);
		this.addToCenterPanel(daysCenterPanel);
		JPanel centerPanel = new JPanel();
		centerPanel.add(row1CenterPanel);
		centerPanel.add(daysCenterPanel);
	}
	myFrame2(String tableName, String idName)
	{
		this();
	}
	static void setTables()
	{
		int count=0
		tableNames[count] = "Course";
		for(String str : new String[]{"Batch","Room","Teacher"})
		{
			if(tableName != str)
			{
				count++;
				tableNames[count] = str;
			}
		}
		if(!tableName.equals("Batch"))
		{
			tableNames[0] = "Batch";
			tableNames[1] = "Course";
		}
		innerBox.tableNames = tableNames;
	}
	static void showTT(String idName, JPanel daysCenterPanel)
	{
		innerBox.idName = idName;//retrieve data from tt and display if present else show 3 CBoxes and a 'Save' btn!!
		//innerBox.daysCenterPanel = daysCenterPanel;
		daysCenterPanel.setLayout(new GridLayout(5,9));
		for(int count_d=0; count_d<5; count_d++)
		for(int count_p=0; count_p<9; count_p++){
			if(myFrame2.innerBoxInfo(idName, count_d, count_p))
				daysCenterPanel.add(new innerBox((int)5).getPanel());//show the saved data
			else
				daysCenterPanel.add(new innerBox("monish").getPanel());//give option to add data
		}
	}
	static ResultSet innerBoxInfo(int day, int period)
	{
			qry = "select "+tableNames[0].charAt(0)+"id, "+
			tableNames[1].charAt(0)+"id, "+
			tableNames[2].charAt(0)+"id from tt"+
			" where ("+tableName.charAt(0)+"id = "+"'"+innerBox.idName+"') && "+
			"(day = "+day+") && "+
			"(period = "+period+")";
			rset = stmt.executeQuery(qry);
			return(rset);
	}
	static void isEntryAvailable(int day, int period)//its functionality can be retrieved from inerBoxInfo
	{
		qry = "select * from tt"+
			" where ("+tableName.charAt(0)+"id = "+"'"+innerBox.idName+"') && "+
			"(day = "+day+") && "+
			"(period = "+period+")";
		rset = stmt.executeQuery(qry);
		return(rset.next())
	}
	static void addToCenterPanel(JPanel daysCenterPanel)
	{
		JButton btnRequest = new JButton("Select a "+tableName+"from the list.");
		btnRequest.setEnabled(false);
		daysCenterPanel.add(btnRequest);
	}
	void disposeMyFrame2()
	{
		dispose(this);
	}
	boolean deleteInnerBoxInfo(int d, int p)
	{
		qry = "delete from tt where (day = "+d+") && (period = "+p+") && (+"+
			(this.tableName).charAt(0)+"id = "+"'"+innerBox.idName+"'
			)";
		try
		{
			stmt.executeUpdate(qry);
			return(true);
		}
		catch(SQLException e)
		{
			System.out.println("myError: "+e.toString());
			return(false);
		}
	}
	String tableName;
	String[] tableNames = new String(3);
	static JButton btnHead = new JButton("Welcome to page 2");
	static JButton btnFoot = new JButton("Waiting for any event");
	static Statement stmt;
	static ResultSet rset;
	static String qry;
}
class innerBox
{
	innerBox()
	{
		this.day = innerBox.d;
		this.period = innerBox.p;
		System.out.println("In innerBox constructor with day and period ="+day+" "+period);
		this.panel = new JPanel();
		panel.set(new GridLayout(4,1));
		panel.add(cmp1);
		panel.add(cmp2);
		panel.add(cmp3);
		panel.add(cmp4);
	}
	innerBox(int n)//show saved data
	{
		this();
		cmp1 = new JButton();
		cmp2 = new JButton();
		cmp3 = new JButton();
		cmp4 = new JButton("Edit");
		cmp1.setEnabled(false);
		cmp2.setEnabled(false);
		cmp3.setEnabled(false);
		ResultSet rSet = myFrame2.innerBoxInfo(this.day, this.period);
		while(rSet.next())
		{
			cmp1.setText(rSet.getString(1));
			cmp2.setText(rSet.getString(2));
			cmp3.setText(rSet.getString(3));
		}
		cmp4.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				if(deleteInnerBoxInfo(this.day, this.period))
				{
					myFrame2.btnFoot.setText("Deleted Successfully");
					new myFrame2(innerBox.tableName, innerBox.idName);
					disposeMyFrame2();
				}
				else
					myFrame2.btnFoot.setText("Error: Might not deleted successfully");
			}
		});
	}
	innerBox(String s)//give CBoxes as options to the user to allocate resources
	{
		this();
		//Perform following step for each cmp123
		//1.)get string[] ready and then construct cmp1 = new JComboBox(String[]);
		
		cmp4 = new JButton("Save");
		cmp4.addActionListener(new ActionEvent()
		{
			public void actionPerformed(ActionEvent event)
			{
				String str1 = cmp1.getSelectedItem();
				String str2 = cmp2.getSelectedItem();
				String str3 = cmp3.getSelectedItem();
				if((!str1).equals("-Select-")) && (!str1.equals(""))
					(!str2.equals("-Select-")) && (!str2.equals(""))
					(!str3.equals("-Select-")) && (!str3.equals("")))
				{
					if(addInnerBoxInfo(this.day, this.period))
					{
						myFrame2.btnFoot.setText("Item Inserted!!");
						new myFrame2(innerBox.tableName, innerBox.idName)
						disposeMyFrame2();
					}
					else
						myFrame2.btnFoot.setText("Error: Might not deleted successfully");
				}
				else
					myFrame2.btnFoot.setText("Error: Select appropriate options from lists!!");
			}
		});
	}
	JPanel getPanel(){
		return (this.panel);
	}
/*	boolean state = false;// true if entry is there for corr. day and period
/	String strCmp1;
	String strCmp2;
	String strCmp3;
	String strCmp4;*/
	JComponent cmp1;
	JComponent cmp2;
	JComponent cmp3;
	JComponent cmp4;
	JPanel panel;
	static String[] tableNames;
	static String idName;
	int day=0;
	int period=0;
	static int d=1;
	static int p=0;
	static String tableName;
	static frame2Caller;
	{	if(d==5 && p==9)
		{
			d=1;
			p=0;
		}
		if(p==9)
		{
			d++;
			p=1;
		}
		else
			p++;
	}
}