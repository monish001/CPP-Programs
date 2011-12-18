////TT1.java : has a 'Back button' only to go back to page1 and hide page2.
//myFrame2-1.java : saved when contruction of myFrame2() was in progress.
//myFrame2-2.java : saved when no compile time error but run time erro is there.
//frame2.java
import java.sql.*;
import java.util.regex.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
class myFrame2 extends JFrame{
	public static void main(String args[])
	{	
		if(args.length != 0){
			myFrame2 frm;
			frm	= new myFrame2(args[0]);
		}
		else
			System.out.println("input argument tablename");
			System.exit(0);
	}
	myFrame2()
	{
		
		
        setTitle("Administrator Screen");
        setSize(600, 400);
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
		innerBox.tableName = tableName;
		setTables();
		innerBox.callByFrame = this;
		btnHead.setEnabled(false);
		btnFoot.setEnabled(false);
		add(btnHead, BorderLayout.NORTH);
		add(btnFoot, BorderLayout.SOUTH);
		JLabel northLabel = new JLabel(tableName+"s:");
		northCBox = new JComboBox(myFrame.initialOptions(tableName, "id"));
		JPanel daysCenterPanel = new JPanel();
		innerBox.daysCenterPanel = daysCenterPanel;
		northCBox.addActionListener(new ActionListener()
		{
			
			public void actionPerformed(ActionEvent event)
			{
				if(!(((String)((JComboBox)event.getSource()).getSelectedItem())).equals("-Select-"))
					showTT();//(String)northCBox.getSelectedItem(), daysCenterPanel);
				else
					btnFoot.setText("Select a "+innerBox.tableName+" from the list!!");
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
		this(tableName);
		myFrame2.showTT();
	}
	static void setTables()
	{
		int count=0;
		innerBox.tableNames[count] = "Course";
		for(String str : new String[]{"Batch","Room","Teacher"})
		{
			if(innerBox.tableName != str)
			{
				count++;
				innerBox.tableNames[count] = str;
			}
		}
		
	}
	static void showTT()
	{
		innerBox.idName = ((String)((myFrame2.northCBox).getSelectedItem()));
		//retrieve data from tt and display if present else show 3 CBoxes and a 'Save' btn!!
		innerBox.daysCenterPanel.removeAll();
		innerBox.daysCenterPanel.setLayout(new GridLayout(5,9));
		for(int count_d=0; count_d<5; count_d++)
		for(int count_p=0; count_p<9; count_p++){
			if(myFrame2.isEntryAvailable(count_d, count_p))
				innerBox.daysCenterPanel.add(new innerBox((int)5).getPanel());//show the saved data
			else
				innerBox.daysCenterPanel.add(new innerBox("monish").getPanel());//give option to add data
		}
	}
	static ResultSet innerBoxInfo(int day, int period)
	{
			qry = "select "+innerBox.tableNames[0].charAt(0)+"id, "+
			innerBox.tableNames[1].charAt(0)+"id, "+
			innerBox.tableNames[2].charAt(0)+"id from tt"+
			" where ("+innerBox.tableName.charAt(0)+"id = "+"'"+innerBox.idName+"') && "+
			"(day = "+day+") && "+
			"(period = "+period+")";
			try
			{
				rset = stmt.executeQuery(qry);
				return(rset);
			}
			catch(SQLException e)
			{
				System.out.println("myError"+e.toString());
				return(null);
			}
	}
	static boolean isEntryAvailable(int day, int period)//its functionality can be retrieved from inerBoxInfo
	{
		qry = "select * from tt"+
			" where ("+innerBox.tableName.charAt(0)+"id = "+"'"+innerBox.idName+"') && "+
			"(day = "+day+") && "+
			"(period = "+period+")";
			try
			{
				rset = stmt.executeQuery(qry);
				return(rset.next());
			}
			catch(SQLException e)
			{
				System.out.println("myError"+e.toString());
				return(false);
			}
	}
	static void addToCenterPanel(JPanel daysCenterPanel)
	{
		JButton btnRequest = new JButton("Select a "+innerBox.tableName+"from the list.");
		btnRequest.setEnabled(false);
		daysCenterPanel.add(btnRequest);
	}
	void disposeMyFrame2()
	{
		System.exit(0);
	}
	static boolean addInnerBoxInfo(int d, int p, String str1, String str2, String str3)
	{
		qry = "insert into tt(day, period, "+
			(innerBox.tableName).charAt(0)+"id, "+innerBox.tableNames[0].charAt(0)+"id, "+innerBox.tableNames[1].charAt(0)+"id, "+innerBox.tableNames[2].charAt(0)+"id) "+
			"values("+d+", "+p+", "+innerBox.idName+", "+str1+", "+str2+", "+str3+")" ;
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
	static boolean deleteInnerBoxInfo(int d, int p)
	{
		qry = "delete from tt where (day = "+d+") && (period = "+p+") && (+"+
			(innerBox.tableName).charAt(0)+"id = "+"'"+innerBox.idName+"')";
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
	static JComboBox northCBox;
	//static JPanel daysCenterPanel;
	//String tableName;
	String[] tableNames = new String[3];
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
		panel.setLayout(new GridLayout(4,1));
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
		try{
			ResultSet rSet = myFrame2.innerBoxInfo(this.day, this.period);
			while(rSet.next())
			{
				((JButton)cmp1).setText((rSet.getString(1)));
				((JButton)cmp2).setText(rSet.getString(2));
				((JButton)cmp3).setText(rSet.getString(3));
			}
		}
		catch(SQLException e)
		{
			System.out.println("myERROR"+e.toString());
		}
		/*cmp4.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				if(myFrame2.deleteInnerBoxInfo(this.day, this.period))
				{
					new myFrame2(innerBox.tableName, innerBox.idName);
					myFrame2.btnFoot.setText("Deleted Successfully");
					callByFrame.disposeMyFrame2();
				}
				else
					myFrame2.btnFoot.setText("Error: Might not deleted successfully");
			}
		});*/
	}
	innerBox(String s)//give CBoxes as options to the user to allocate resources
	{
		this();
		//Perform following step for each cmp123
		//1.)get string[] ready and then construct cmp1 = new JComboBox(String[]);
		cmp1 = new JComboBox(findAvailList());
		cmp2 = new JComboBox(findAvailList());
		cmp3 = new JComboBox(findAvailList());
		cmp4 = new JButton("Save");
		/*cmp4.addActionListener(new ActionEvent()
		{
			public void actionPerformed(ActionEvent event)
			{
				String str1 = (String)(((JComboBox)cmp1).getSelectedItem());
				String str2 = (String)(((JComboBox)cmp2).getSelectedItem());
				String str3 = (String)(((JComboBox)cmp3).getSelectedItem());
				if((!str1.equals("-Select-")) && (!str1.equals("")) &&
					(!str2.equals("-Select-")) && (!str2.equals("")) &&
					(!str3.equals("-Select-")) && (!str3.equals("")))
				{
					if(myFrame2.addInnerBoxInfo(day, period, str1, str2, str3))
					{
						new myFrame2(innerBox.tableName, innerBox.idName);
						myFrame2.btnFoot.setText("Item Inserted!!");
						callByFrame.disposeMyFrame2();
					}
					else
						myFrame2.btnFoot.setText("Error: Might not deleted successfully");
				}
				else
					myFrame2.btnFoot.setText("Error: Select appropriate options from lists!!");
			}
		});*/
	}
	String[] findAvailList(){
		String[] fullList = myFrame.initialOptions(innerBox.tableName, "id"); int fullNo = myFrame.noOfItems;
		String[] busyList = myFrame.initialOptions("tt", innerBox.tableName.charAt(0)+"id"); int busyNo = myFrame.noOfItems;
		String[] availList = null; 
		if(fullNo == 0)
			;
		else
			availList = new String[fullNo - busyNo];		
		String text = "";
		for(String s1 : busyList)
			text += (s1+" ");
		{
			int count = 0;
			Pattern p = null;
			Matcher m = null;
			for(String s1 : fullList)
			{
				p = Pattern.compile(s1);
				p.matcher(text);
				while(m.find())
				{
					count++;
					availList[count] = text.substring(m.start(), m.end());
				}
			}
			
		}
		return(availList);
	}
	JPanel getPanel(){
		return (this.panel);
	}
	static myFrame2 callByFrame;
	JComponent cmp1;
	JComponent cmp2;
	JComponent cmp3;
	JComponent cmp4;
	JPanel panel;
	static String[] tableNames = null;
	static String idName;
	int day=0;
	int period=0;
	static int d=1;
	static int p=0;
	static String tableName;
	static JPanel daysCenterPanel;
	{	
		if(d==5 && p==9)
		{
			d=1;
			p=0;
		}
		else if(p==9)
		{
			d++;
			p=1;
		}
		else
			p++;
	}
}