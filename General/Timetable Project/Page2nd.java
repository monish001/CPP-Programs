//Page2nd1.java: Error free, action listeners for edit btn and save btn of inner boxes implemented
//				 but still not satisfactory IMPLEMENTATION
//Page2nd2.java: Added Scrollbar
//Page2nd3.java: added another BorderLayout inside previously existing one.
//Page2nd4.java: class NotSavedInnerBox and class SavedInnerBox being derived from abstract class InnerBox
//				 so that objects of former 2 classes can be referenced by abstract class InnerBox instance.
//Page2nd5.java: modified class SavedInnerBox where 'setEnabled(false)' buttons viz. btn1, btn2, btn3
//				 replaced by 'JLabel' with same names.
//Page2nd6.java: Added border to each inner box.
//Page2nd7.java: synchronised with Page1(file TT_GUI16.java)
//Page2nd8.java: errors are there, maybe because JPanel[][] is used
//Page2nd9.java: Clicking on save/edit button repaints its innerbox only 
//				 rather than full 45 innerboxes + synchronised with Page1(file TT_GUI16.java)
//				 error: batch and room comboBoxes gives run-time errors.
//Page2nd10.java: prev wrong implementation of busyList[] corrected +
//				  synchronised with Page1(file TT_GUI16.java)

//Features coming soon:
//Time table in printable form(like ms excel .xls format) which will provide printing option.
//menu bar 
//options for save and open
//option for undo
//option for redo
import java.sql.*;
import java.util.regex.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import java.awt.event.*;
public class Page2nd extends JFrame// implements ActionListener
{
	public static void main(String[] args)
	{
		Page2nd p1;
		p1= new Page2nd();
	}
	Page2nd()
	{
        //Frame Details
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
		this.setTitle("Administrator Screen, Page2/2");
		this.setExtendedState(MAXIMIZED_BOTH);
		//this.setSize(600,700);
		//Header and Footer
		btnHead.setEnabled(false);
		btnFoot.setEnabled(false);
		add(btnHead, BorderLayout.NORTH);
		btnHead.setText("Welcome to page 2");
		add(btnFoot, BorderLayout.SOUTH);
		btnFoot.setText("Waiting for any event");
		//BORDERLayout.CENTER
		JPanel centerPanel = new JPanel();
		centerPanel.setLayout(new BorderLayout());//GridBagLayout());
		JPanel row1Panel = new JPanel();		//row1Panel.setBounds(1,25,1024,40);
		JPanel row7Panel = new JPanel();		//row1Panel.setBounds(1,700,1024,40);
		centerPanel.add(row1Panel, BorderLayout.NORTH);//new GBC(0,0,1,1).setWeight(100,100));
		centerPanel.add(Page2nd.scrollPane, BorderLayout.CENTER);//new GBC(0,1,1,5).setWeight(100,100).setIpad(900,600));
		centerPanel.add(row7Panel, BorderLayout.SOUTH);//new GBC(0,6,1,1).setWeight(100,100));
		add(centerPanel, BorderLayout.CENTER);
		//row1 components batch
		//new myFrame();
		String[] cbOptions;
		//row1 batch
		JComboBox bCBox;
		JLabel bLabel = new JLabel("Batch: ");
		cbOptions = myFrame.initialOptions("Batch", "id");
		bCBox = new JComboBox(cbOptions);
		bCBox.addActionListener(this.addListener("Batch"));//, (String)(bCBox.getSelectedItem())));
		//row1 room
		JComboBox rCBox;
		JLabel rLabel = new JLabel("Room: ");
		cbOptions = myFrame.initialOptions("Room", "id");
		rCBox = new JComboBox(cbOptions);
		rCBox.addActionListener(this.addListener("Room"));//, (String)(bCBox.getSelectedItem())));
		//row1 teacher
		JComboBox tCBox;
		JLabel tLabel = new JLabel("Teacher: ");
		cbOptions = myFrame.initialOptions("Teacher", "id");
		tCBox = new JComboBox(cbOptions);
		tCBox.addActionListener(this.addListener("Teacher"));//, (String)(bCBox.getSelectedItem())));
		//row1
		row1Panel.add(bLabel);
		row1Panel.add(bCBox);
		row1Panel.add(rLabel);
		row1Panel.add(rCBox);
		row1Panel.add(tLabel);
		row1Panel.add(tCBox);
		//row7
		JButton btnBack = new JButton("Back");
		btnBack.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					//new myFrame();//page1rowTypeA.viewPage1();
					//dispose();
					page1rowTypeA.viewPage1();
				}
			}
		);
		row7Panel.add((JButton)(btnBack));
		//row7Panel.add(new JButton("go"));
		//row7Panel.add(new JButton("print"));
		//pack();
	}
	public ActionListener addListener(final String tableName)//for the 3 JComboBoxes in row1
	{
		return(new ActionListener()
		{
				public void actionPerformed(ActionEvent e)
				{
					(Page2nd.btnFoot).setText("Loading.. Please Wait!!");
					JComboBox cbox = (JComboBox)(e.getSource()); 
					String item = (String)(cbox.getSelectedItem());
					if(item != null)
					{
						if((item.charAt(0)) != '-')
						{
							try	
							{
								ParticularTT ptt = new ParticularTT(tableName, item);
								(Page2nd.gridPanel).removeAll();
								(Page2nd.gridPanel).add(ptt.getPanel());
							}
							catch(SQLException error)
							{
								System.out.println("myERROR, in actionPerformed()"+error.toString());
							}
							(Page2nd.gridPanel).repaint();
						}
					}
					else
					{
						System.out.println("Page2nd.java: Line 127: null selected from "+tableName+" list..");
						(Page2nd.btnFoot).setText("Select appropriate option from the lists.");
					}
				}
		});
	}
	static JPanel gridPanel = new JPanel();
	static JScrollPane scrollPane = new JScrollPane(gridPanel);
	static JButton btnHead = new JButton();
	static JButton btnFoot = new JButton();	
}
class ParticularTT
{
	ParticularTT(String tableName, String idName) throws SQLException//constructor
	{
		try//initialising a statement object
		{
			ParticularTT.con = new JdbcConnection();
			ParticularTT.c = con.conn();
			ParticularTT.stmt = c.createStatement();
		}
		catch(SQLException err)
		{
			System.out.println("a.myError in isEntrySaved()"+err.toString());
		}
		//System.out.println(idName+" selected from "+tableName);
		String[] tableNames = new String[3];
		int count=0;
		tableNames[count] = "Course";
		for(String str : new String[]{"Batch","Room","Teacher"})
		{
			if(!tableName.equals(str))
			{
				count++;
				tableNames[count] = str;
				//System.out.println(str+" added to tableNames[]");
			}
		}
		pTTPanel = new JPanel();
		pTTPanel.setLayout(new GridLayout(5,9));
		//InnerBox[][] box = new InnerBox[9][5];
		for(int d=1; d<=5; d++)
		for(int p=1; p<=9; p++)
		{
			ResultSet rSet = this.isEntrySaved(d, p, tableName, idName, tableNames);
			if(!(rSet.next()))//give options to save
			{
				addNotSavedInnerBox(d, p, tableName, idName, tableNames);
			}
			else
			{
				addSavedInnerBox(d, p, rSet, tableName, idName, tableNames);
			}
			//pTTPanel.add(box.getPanel());
		}
		(Page2nd.btnFoot).setText("Timetable for "+tableName+" = "+idName+" loaded.");
	}
	public void addNotSavedInnerBox(int d, int p, String tableName, String idName, String[] tableNames)//give options to save
	{
		NotSavedInnerBox box = new NotSavedInnerBox();
		(box.btn4).addActionListener(addListener(box, d, p, tableName, idName, tableNames));
		String[] available = myFrame.initialOptions(tableNames[0], "id");
		available[0] = "-Select "+tableNames[0]+"-";
		for(String str : available)
			(box.CBox1).addItem(str);
		available = findAvailList(d,p,tableNames[1]);
		for(String str : available)
			(box.CBox2).addItem(str);
		available = findAvailList(d,p,tableNames[2]);
		for(String str : available)
			(box.CBox3).addItem(str);
		pTTPanel.add(box.getPanel());
	}
	public void addSavedInnerBox(int d, int p, ResultSet rSet, String tableName, String idName, String[] tableNames)
	{
		SavedInnerBox box = new SavedInnerBox();
		(((SavedInnerBox)(box)).btn4).addActionListener(addListener(((SavedInnerBox)(box)), d, p, tableName, idName, tableNames));
		try
		{
			(((SavedInnerBox)(box)).btn1).setText(rSet.getString(1));
			(((SavedInnerBox)(box)).btn2).setText(rSet.getString(2));
			(((SavedInnerBox)(box)).btn3).setText(rSet.getString(3));
		}
		catch(SQLException se){System.out.println("myERROR line 200"+se.toString());}
		pTTPanel.add(((SavedInnerBox)(box)).getPanel());	
	}
	public void addNotSavedInnerBox(SavedInnerBox oldBox, int d, int p, String tableName, String idName, String[] tableNames)//give options to save
	{
		NotSavedInnerBox box = new NotSavedInnerBox(oldBox);
		(((NotSavedInnerBox)(box)).btn4).addActionListener(addListener(((NotSavedInnerBox)(box)), d, p, tableName, idName, tableNames));
		String[] available = myFrame.initialOptions(tableNames[0], "id");
		available[0] = "-Select "+tableNames[0]+"-";
		for(String str : available)
			(((NotSavedInnerBox)(box)).CBox1).addItem(str);
		available = findAvailList(d,p,tableNames[1]);
		for(String str : available)
			(((NotSavedInnerBox)(box)).CBox2).addItem(str);
		available = findAvailList(d,p,tableNames[2]);
		for(String str : available)
			(((NotSavedInnerBox)(box)).CBox3).addItem(str);
		(box.getPanel()).validate();
		//(box.getPanel()).repaint();
	}
	public void addSavedInnerBox(NotSavedInnerBox oldBox, int d, int p, ResultSet rSet, String tableName, String idName, String[] tableNames)
	{
		SavedInnerBox box = new SavedInnerBox(oldBox);
		(((SavedInnerBox)(box)).btn4).addActionListener(addListener(((SavedInnerBox)(box)), d, p, tableName, idName, tableNames));
		try
		{
			(((SavedInnerBox)(box)).btn1).setText(rSet.getString(1));
			(((SavedInnerBox)(box)).btn2).setText(rSet.getString(2));
			(((SavedInnerBox)(box)).btn3).setText(rSet.getString(3));
		}
		catch(SQLException se){System.out.println("myERROR line 200"+se.toString());}
		(box.getPanel()).validate();
		//(box.getPanel()).repaint();
	}
	public ActionListener addListener(final SavedInnerBox box, final int d, final int p, final String tableName, final String idName, final String[] tableNames)
	{//when edit button is pressed in innerBox => deletes the entry and replaces SavedInnerBox with NotSavedInnerBox
		return(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				String qry = "delete from tt where "+
					"(day = "+d+") and (period = "+p+") and ("+tableName.charAt(0)+"id = '"+idName+"')";
				try
				{
					System.out.println("Query(delete) for edit btn: "+qry);
					stmt.executeUpdate(qry);
					(Page2nd.btnFoot).setText("Entry deleted, you can now enter the new values..");
				}
				catch(SQLException err)
				{
					System.out.println("Edit button "+err.toString());
					(Page2nd.btnFoot).setText("Try again..error in edit btn or deletion");
				}
				
				addNotSavedInnerBox(box, d,  p, tableName, idName, tableNames);
				//.validate();//repaint(); it will be done by above called function
			}
		});
	}
	public ActionListener addListener(final NotSavedInnerBox box, final int d, final int p, final String tableName, final String idName, final String[] tableNames)
	{//when save button is pressed in innerBox
		return(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				if(((box.CBox1).getSelectedIndex() != 0) && ((box.CBox2).getSelectedIndex() != 0) && ((box.CBox3).getSelectedIndex() != 0))
				{
					String qry = "insert into tt(day, period, "+
						(tableName.charAt(0))+"id, "+(tableNames[0].charAt(0))+"id, "+(tableNames[1].charAt(0))+"id, "+(tableNames[2].charAt(0))+"id) "+
						"values("+d+", "+p+", '"+idName+"', '"+((box.CBox1).getSelectedItem())+"', '"+((box.CBox2).getSelectedItem())+"', '"+((box.CBox3).getSelectedItem())+"')";
					try
					{
						System.out.println("Query(insert) for save btn: "+qry);
						stmt.executeUpdate(qry);
						(Page2nd.btnFoot).setText("Entry successfully inserted..");
					}
					catch(SQLException err)
					{
						System.out.println("Query(insert) for save btn: "+err.toString());
						(Page2nd.btnFoot).setText("Try Again.. Error in Save button or insert query");
					}
					
					//ResultSet rSet = this.isEntrySaved(d, p, tableName, idName, tableNames);
					ResultSet rset;
					qry = "select "+
						tableNames[0].charAt(0)+"id, "+(tableNames[1].charAt(0))+"id, "+(tableNames[2].charAt(0))+"id from tt"+
						" where ("+tableName.charAt(0)+"id = "+"'"+idName+"') and "+
						"(day = "+d+") and "+
						"(period = "+p+")";
					rset = null;
					try
					{
						rset = stmt.executeQuery(qry);
						//c.close();
					}
					catch(SQLException e)
					{
						System.out.println("b.myError in isEntrySaved()"+e.toString());
					}
					try{
					if(rset.next()){
						addSavedInnerBox(box, d,  p, rset, tableName, idName, tableNames);
					}
					else
					{
						System.out.println("error : line254, rset.next() equal to false!!");
					}}
					catch(SQLException excp){System.out.println("myERROR : line 273"+excp.toString());}
				}
				else
					(Page2nd.btnFoot).setText("Select appropriate options from lists.");
			}
		});
	}
	public JPanel getPanel()
	{
		return(pTTPanel);
	}
	public ResultSet isEntrySaved(int d, int p, String tableName, String idName, String[] tableNames)// throws SQLException
	{
		
       	ResultSet rset;
		String qry = "select "+tableNames[0].charAt(0)+"id, "+
		tableNames[1].charAt(0)+"id, "+
		tableNames[2].charAt(0)+"id from tt"+
		" where ("+tableName.charAt(0)+"id = "+"'"+idName+"') and "+
		"(day = "+d+") and "+
		"(period = "+p+")";
		//System.out.println("Query in isEntrySaved() : "+qry);
		rset = null;
		try
		{
			rset = stmt.executeQuery(qry);
			//c.close();
		}
		catch(SQLException e)
		{
			System.out.println("b.myError in isEntrySaved()"+e.toString());
		}
		return(rset);
	}
	public static String[] findAvailList(int d,int p,String tableName)
	{
		//new myFrame();
		String[] fullList = ParticularTT.initialOptions(tableName, "id"); int fullNo = ParticularTT.noOfItems;
		String[] busyList = ParticularTT.initialOptions(d, p, "tt", tableName.charAt(0)+"id"); int busyNo = ParticularTT.noOfItems;
		String[] availList; int availNo = fullNo-busyNo +1; 
		if(availNo <= 1)
			availList = null;
		else
		{
			availList = new String[availNo];		
			int count = 0;
			availList[0] = "-Select "+tableName+"-";
			boolean flag = true;//true means f is available
			for(String f : fullList)
			{
				flag = true;
				for(String b : busyList){
					if(b.equals(f))
					{
						flag = false;
						break;
					}
				}
				if(flag == true)
				{
					count++;
					if(count >= availNo)
						System.out.println("Page2nd.java: 380: overflow in availList of "+tableName);
					availList[count] = f;
				}
			}
		}
		return(availList);
	}
	public static String[] initialOptions( int d, int p, String tname , String cname)//returns first item as -Select-
		{
		int noOfRows=0;
		String qry=new String("select count(*) from "+tname+" where (day = "+d+") and (period = "+p+")");//Execute queries and/or updates
		//System.out.println("Page2nd.java: line 391 : "+qry);
		String[] CBoxOptions = null;
		try
		{
			rset=stmt.executeQuery(qry);
			while(rset.next())
			{
				noOfRows = rset.getInt(1);
				ParticularTT.noOfItems = noOfRows;
			}
			CBoxOptions = new String[noOfRows+1];
			qry=new String("select "+cname+" from "+tname+" where (day = "+d+") and (period = "+p+")");//Execute queries and/or updates
			//System.out.println("Page2nd.java: line 402 : "+qry+"\nNo of rows = "+noOfRows+"\n");
			rset=stmt.executeQuery(qry);
			CBoxOptions[0] = "-Select-";//"-Select "+tname+"-";//
			for(int count=1; rset.next(); count++)
			{
				CBoxOptions[count] = rset.getString(1);
			}
		}
		catch(Exception e)
		{
			System.out.println("2.)Error in InitialOptions "+e.toString());
		}			
		return (CBoxOptions);
	}
	public static String[] initialOptions( String tname , String cname)//returns first item as -Select-
		{
		int noOfRows=0;
		String qry=new String("select count(*) from "+tname);//Execute queries and/or updates
		String[] CBoxOptions = null;
		try
		{
			rset=stmt.executeQuery(qry);
			while(rset.next())
			{
				noOfRows = rset.getInt(1);
				ParticularTT.noOfItems = noOfRows;
			}
			CBoxOptions = new String[noOfRows+1];
			qry=new String("select "+cname+" from "+tname);//Execute queries and/or updates
			rset=stmt.executeQuery(qry);
			CBoxOptions[0] = "-Select-";//"-Select "+tname+"-";//
			for(int count=1; rset.next(); count++)
			{
				CBoxOptions[count] = rset.getString(1);
			}
		}
		catch(Exception e)
		{
			System.out.println("2.)Error in InitialOptions "+e.toString());
		}			
		return (CBoxOptions);
	}
	static int noOfItems =0;
	JPanel pTTPanel;
	
	static JdbcConnection con;
	static Connection c=null;
	static Statement stmt=null; 
	static ResultSet rset = null;
}
abstract class InnerBox
{
	InnerBox()
	{
		myPanel.setLayout(new GridLayout(4,1));
		myPanel.setBorder(new SoftBevelBorder(EtchedBorder.LOWERED));
		//myPanel.setBorder(BorderFactory.createLoweredBevelBorder());
	}
	public JPanel getPanel()
	{
		return(this.myPanel);
	}
	protected JPanel myPanel = new JPanel();
}
class SavedInnerBox extends InnerBox
{
	SavedInnerBox()
	{
		myPanel.add(btn1);
		myPanel.add(btn2);
		myPanel.add(btn3);
		myPanel.add(btn4);
	}
	SavedInnerBox(NotSavedInnerBox box)
	{
		this.myPanel = box.getPanel();
		(myPanel).removeAll();
		myPanel.add(btn1);
		myPanel.add(btn2);
		myPanel.add(btn3);
		myPanel.add(btn4);
		myPanel.validate();
	}
	public JLabel btn1 = new JLabel();
	public JLabel btn2 = new JLabel();
	public JLabel btn3 = new JLabel();
	public JButton btn4 = new JButton("Edit");
}
class NotSavedInnerBox extends InnerBox
{
	NotSavedInnerBox()
	{
		myPanel.add(CBox1);
		myPanel.add(CBox2);
		myPanel.add(CBox3);
		myPanel.add(btn4);
	}
	NotSavedInnerBox(SavedInnerBox box)
	{
		this.myPanel = box.getPanel();
		(myPanel).removeAll();
		myPanel.add(CBox1);
		myPanel.add(CBox2);
		myPanel.add(CBox3);
		myPanel.add(btn4);
		myPanel.validate();
	}
	public JComboBox CBox1 = new JComboBox();
	public JComboBox CBox2 = new JComboBox();
	public JComboBox CBox3 = new JComboBox();
	public JButton btn4 = new JButton("Save");
}