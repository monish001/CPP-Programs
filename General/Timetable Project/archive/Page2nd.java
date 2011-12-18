import java.sql.*;
import java.util.regex.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
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
		//this.setSize(600,400);
		
		//Header and Footer
		btnHead.setEnabled(false);
		btnFoot.setEnabled(false);
		add(btnHead, BorderLayout.NORTH);
		btnHead.setText("Welcome to page 2");
		add(btnFoot, BorderLayout.SOUTH);
		btnFoot.setText("Waiting for any event");
		//BORDERLayout.CENTER

		JPanel centerPanel = new JPanel();
		centerPanel.setLayout(new GridBagLayout());
		
		JPanel row1Panel = new JPanel();
		row1Panel.setBounds(1,25,1024,40);
		JPanel row7Panel = new JPanel();
		row1Panel.setBounds(1,700,1024,40);
		centerPanel.add(row1Panel, new GBC(0,0,1,1).setWeight(100,100));
		centerPanel.add(Page2nd.gridPanel, new GBC(0,1,1,5).setWeight(100,100).setIpad(100,100));
		centerPanel.add(row7Panel, new GBC(0,6,1,1).setWeight(100,100));
		add(centerPanel, BorderLayout.CENTER);
		
		//row1 components batch
		new myFrame();
		String[] cbOptions;
		//row1A
		JComboBox bCBox;
		JLabel bLabel = new JLabel("Batch: ");
		cbOptions = myFrame.initialOptions("Batch", "id");
		bCBox = new JComboBox(cbOptions);
		bCBox.addActionListener(addListener("Batch"));//, (String)(bCBox.getSelectedItem())));
		//row1B
		JComboBox rCBox;
		JLabel rLabel = new JLabel("Room: ");
		cbOptions = myFrame.initialOptions("Room", "id");
		rCBox = new JComboBox(cbOptions);
		rCBox.addActionListener(addListener("Room"));//, (String)(bCBox.getSelectedItem())));
		//row1C
		JComboBox tCBox;
		JLabel tLabel = new JLabel("Teacher: ");
		cbOptions = myFrame.initialOptions("Teacher", "id");
		tCBox = new JComboBox(cbOptions);
		tCBox.addActionListener(addListener("Teacher"));//, (String)(bCBox.getSelectedItem())));
		//row1

		row1Panel.add(bLabel);
		row1Panel.add(bCBox);
		row1Panel.add(rLabel);
		row1Panel.add(rCBox);
		row1Panel.add(tLabel);
		row1Panel.add(tCBox);

		//row7

		row7Panel.add(new JButton("Back"));
		row7Panel.add(new JButton("go"));
		row7Panel.add(new JButton("print"));
		
		//row 2 to 6 = gridPanel
		//Page2nd.gridPanel.add(new JButton("gridPanel here"));
		pack();
		}
	public ActionListener addListener(final String tableName)//, final String idName)
	{
		return(new ActionListener()
		{
				public void actionPerformed(ActionEvent e)
				{
					JComboBox cbox = (JComboBox)(e.getSource()); 
					String item = (String)(cbox.getSelectedItem());
					if(!item.equals("-Select-"))
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
						pack();
					}
				}
		});
	}
	static JPanel gridPanel = new JPanel();
	static JButton btnHead = new JButton();
	static JButton btnFoot = new JButton();	
}
class ParticularTT
{
	ParticularTT(String tableName, String idName) throws SQLException
	{
		try
		{
			ParticularTT.con = new JdbcConnection();
			ParticularTT.c = con.conn();
			ParticularTT.stmt = c.createStatement();
		}
		catch(SQLException err)
		{
			System.out.println("a.myError in isEntrySaved()"+err.toString());
		}
		System.out.println(idName+" selected from "+tableName);
		String[] tableNames = new String[3];
		int count=0;
		tableNames[count] = "Course";
		for(String str : new String[]{"Batch","Room","Teacher"})
		{
			if(!tableName.equals(str))
			{
				count++;
				tableNames[count] = str;
				System.out.println(str+"added to tableNames[]");
			}
		}
		pTTPanel = new JPanel();
		pTTPanel.setLayout(new GridLayout(5,9));
		for(int d=1; d<=5; d++)
		for(int p=1; p<=9; p++)
		{
			ResultSet rSet = this.isEntrySaved(d, p, tableName, idName, tableNames);
			if(!(rSet.next()))//give options to save
			{
				NotSavedInnerBox box = new NotSavedInnerBox();
				(box.btn4).addActionListener(new addListener(box));
				String[] available = myFrame.initialOptions(tableNames[0], "id");
				available[0] = "-Select "+tableNames[0]+"-";
				for(String str : available)
					(box.CBox1).addItem(str);
				available = findAvailList(tableNames[1]);
				for(String str : available)
					(box.CBox2).addItem(str);
				available = findAvailList(tableNames[2]);
				for(String str : available)
					(box.CBox3).addItem(str);
				pTTPanel.add(box.getPanel());
			}
			else
			{
				int number =0;
				SavedInnerBox box = new SavedInnerBox();
				(box.btn4).addActionListener(new addListener(box));
				System.out.println("rSet.next() count:"+ (++number));
				(box.btn1).setText(rSet.getString(1));
				(box.btn2).setText(rSet.getString(2));
				(box.btn3).setText(rSet.getString(3));
				pTTPanel.add(box.getPanel());
			}
		}
	}
	public ActionListener addListener(final SavedInnerBox box)// implements ActionListener
	{
				return(new ActionListener()
				{
					public void actionPerformed(ActionEvent event)
					{
						String qry = "delete from tt where (day = "+d+") and (period = "+p+") and ("+tableName.charAt(0)+"id = "+idName+")";
						try
						{
							System.out.println("Query: "+qry);
							stmt.executeUpdate(qry);
							(Page2nd.btnFoot).setText("Enter the new values..");
							
						}
						catch(SQLException err)
						{
							System.out.println("Edit button "+err.toString());
							(Page2nd.btnFoot).setText("Try again..");
						}
					}
				});
	}
	public ActionListener addListener(final SavedInnerBox box)// implements ActionListener
	{
				return(new ActionListener(){
					public void actionPerformed(ActionEvent event)
					{
						if(((box.CBox1).getSelectedIndex() != 0) && ((box.CBox2).getSelectedIndex() != 0) && ((box.CBox3).getSelectedIndex() != 0))
						{
							String qry = "insert into tt values(day, period,"+
								tableName.charAt(0)+"id,"+tableNames[0].charAt(0)+"id,"+tableNames[1].charAt(0)+"id,"+tableNames[2].charAt(0)+"id"+
								"set("+d+","+p+","+idName+","+(box.CBox1).getSelectedItem()+","+(box.CBox2).getSelectedItem()+","+(box.CBox3).getSelectedItem()+")";
							try
							{
								System.out.println("Query: "+qry);
								stmt.executeUpdate(qry);
								(Page2nd.btnFoot).setText("Enter the new values..");
							}
							catch(SQLException err)
							{
								System.out.println("Edit button "+err.toString());
								(Page2nd.btnFoot).setText("Try again..");
							}
						}
						else
							(Page2nd.btnFoot).setText("Try again..");
					}
				});

	}
	public JPanel getPanel()
	{
		return(pTTPanel);
	}
	public ResultSet isEntrySaved(int d, int p, String tableName, String idName, String[] tableNames)// throws SQLException
	{
		
       	ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
		String qry = "select "+tableNames[0].charAt(0)+"id, "+
		tableNames[1].charAt(0)+"id, "+
		tableNames[2].charAt(0)+"id from tt"+
		" where ("+tableName.charAt(0)+"id = "+"'"+idName+"') and "+
		"(day = "+d+") and "+
		"(period = "+p+")";
		System.out.println("Query in isEntrySaved() : "+qry);
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
	public static String[] findAvailList(String tableName)
	{
		//new myFrame();
		String[] fullList = ParticularTT.initialOptions(tableName, "id"); int fullNo = ParticularTT.noOfItems;
		String[] busyList = ParticularTT.initialOptions("tt", tableName.charAt(0)+"id"); int busyNo = ParticularTT.noOfItems;
		String[] availList = null; int availNo = fullNo-busyNo +1; 
		if(availNo <= 1)
			;
		else
		{
			availList = new String[availNo];		
			int count = 0;
			availList[0] = "-Select "+tableName+"-";
			boolean flag = true;
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
					availList[count] = f;
				}
			}
		}
		return(availList);
//	return(new String{"monish","gupta"})
	}
	public static String[] initialOptions( String tname , String cname)
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
	//static String query;
}
class GBC extends GridBagConstraints
{
	public GBC(int gridX, int gridY, int gridWidth, int gridHeight)
	{
		this.gridx = gridX;
		this.gridy = gridY;
		this.gridwidth = gridWidth;
		this.gridheight = gridHeight;
	}
	public GBC setIpad(int x, int y)
	{
		this.ipadx = x;
		this.ipady = y;
		return(this);
	}
	public GBC setWeight(double weightX, double weightY)
	{
		this.weightx = weightX;
		this.weighty = weightY;
		return(this);
	}
}
class SavedInnerBox
{
	SavedInnerBox()
	{
		btn1.setEnabled(false);
		btn2.setEnabled(false);
		btn3.setEnabled(false);
		myPanel.setLayout(new GridLayout(4,1));
		myPanel.add(btn1);
		myPanel.add(btn2);
		myPanel.add(btn3);
		myPanel.add(btn4);
	}
	public JPanel getPanel()
	{
		return(this.myPanel);
	}
	JButton btn1 = new JButton();
	JButton btn2 = new JButton();
	JButton btn3 = new JButton();
	JButton btn4 = new JButton("Edit");
	JPanel myPanel = new JPanel();
}
class NotSavedInnerBox
{
	NotSavedInnerBox()
	{
		myPanel.setLayout(new GridLayout(4,1));
		myPanel.add(CBox1);
		myPanel.add(CBox2);
		myPanel.add(CBox3);
		myPanel.add(btn4);
	}
	public JPanel getPanel()
	{
		return(this.myPanel);
	}
	JComboBox CBox1 = new JComboBox();
	JComboBox CBox2 = new JComboBox();
	JComboBox CBox3 = new JComboBox();
	JButton btn4 = new JButton("Save");
	JPanel myPanel = new JPanel();
}