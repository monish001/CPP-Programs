//All four rows (without Event Listeners ) created and saved in TT_GUI7.java
//TT_GUI9.java: Draw GUI of Page1 and initialises the CBoxes from database tables.
//TT_GUI10.java: TT_GUI9.java + unsuccessful operations in database + working in cboxes
//TT_GUI11.java: prev + successful operations in database + working in cboxes + consistency assured 
//				 + tf an south for conformation msgs replaced by button+ addTextfieldsToMyInnerPanel() replaced by its definition.
//TT_GUI12.java: fully working but isolated
//TT_GUI13.java: Final Page 1: prev+ func for the page to view page1 and hide page2.
//TT_GUI14.java: prev + check on buttons implemented.
//TT_GUI15.java: prev + column option in CBoxOptions
import java.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class TT_GUI{
	public static void main(String[] args){
		//myFrame frame;
		EventQueue.invokeLater(new Runnable()
		{
            public void run(){
                    myFrame frame=new myFrame();
                    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    frame.setVisible(true);
            }
        });
	}
}
class myFrame extends JFrame{
    myFrame(){
        setTitle("Administrator Screen");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		setResizable(false); 
		page1rowTypeA.Page1frame=this;
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
		mainPanel = new JPanel();//add to borderlayout.centre 
		mainPanel.setLayout(new GridLayout(6,1));

		page1rowTypeA Trow = new page1rowTypeA(mainPanel, "Batch", myFrame.initialOptions("Batch", "id"), 25);

		page1rowTypeA Crow = new page1rowTypeA(mainPanel, "Course", myFrame.initialOptions("Course", "id"), 60);

		page1rowTypeA Grow = new page1rowTypeA(mainPanel, "Room", myFrame.initialOptions("Room", "id"), 95);

		page1rowTypeA Rrow = new page1rowTypeA(mainPanel, "Teacher", myFrame.initialOptions("Teacher", "id"), 130);
		mainPanel.add(page1rowTypeA.btnGo);
		mainPanel.add(page1rowTypeA.nextPanel);
	    add(mainPanel, BorderLayout.CENTER);//adds mainPanel to the frame
		add(page1rowTypeA.btn_south, BorderLayout.SOUTH);
		add(page1rowTypeA.btnHead, BorderLayout.NORTH);
		//pack();
    }
	public static String[] initialOptions( String tname , String cname)
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
				myFrame.noOfItems = noOfRows;
			}
			CBoxOptions = new String[noOfRows+1];
			qry=new String("select "+cname+" from "+tname);//Execute queries and/or updates
			rset=stmt.executeQuery(qry);
			CBoxOptions[0] = "-Select "+tname+"-";//"-Select-";//
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
	public static boolean insert(String itemToInsert, String tName)
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
	}
	JPanel mainPanel;
	public static int noOfItems;
    private static final int DEFAULT_WIDTH  = 600;
    private static final int DEFAULT_HEIGHT = 400;
	static Statement stmt;
	static ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
	static String qry;
}
class page1rowTypeA implements ActionListener{
	page1rowTypeA(JPanel myPanel, String tName,String[] CBoxOptions, int posY){
		this.tName =  tName;
        JLabel myLabel = new JLabel(tName);
        myCBox=new JComboBox(CBoxOptions);
		tf1 = new JTextField("Insert "+tName+":");
		btnInsert = new JButton("Insert");//Insert
		btnUpdate = new JButton("Update");//Update
		btnDelete = new JButton("Delete");//Delete
		btnInsert.addActionListener(this);
		btnUpdate.addActionListener(this);
		btnDelete.addActionListener(this);
		myInnerPanel.add(tf1);//add tf1 to myInnerPanel
        myInnerPanel.add(btnInsert);//add btn to myInnerPanel			
        myInnerPanel.add(btnUpdate);//add btn to myInnerPanel			
        myInnerPanel.add(btnDelete);//add btn to myInnerPanel			
		JPanel OPanel = new JPanel();
        OPanel.add(myLabel);// myLabel.setBounds(25, posY, 70, 30);//add faceLabel to OPanel
        OPanel.add(myCBox); //myCBox.setBounds(100, posY, 70, 30);//add faceCBox to OPanel 
		OPanel.add(myInnerPanel);// myInnerPanel.setBounds(175, posY, 70, 30);//add inner panel to OPanel
		myPanel.add(OPanel);//add OPanel to myPanel
		OPanel.setBounds(25, posY, 40, 300);
	}
	public void actionPerformed(ActionEvent event)
	{
		boolean db_status = false;
		String btnLabel = event.getActionCommand();
		if(btnLabel == "Insert")
		{
			String itemToInsert = tf1.getText();
			if((!itemToInsert.equals("Insert "+tName+":")) && (!itemToInsert.equals("")) && (!itemToInsert.equals("-Select-")))
			{
				db_status = myFrame.insert(itemToInsert, tName);
				if(db_status)
				{
					myCBox.addItem(itemToInsert);
					btn_south.setText(itemToInsert +" inserted..");
				}
			}
			else
				btn_south.setText(itemToInsert +" NOT inserted, select appropriate option for "+tName+"..");
		}
		else if(btnLabel == "Update")
		{	
			String newItem = tf1.getText();		
			if((myCBox.getSelectedIndex() != -1) && (myCBox.getSelectedIndex() != 0))
			{
				if((newItem != "Insert "+tName+":") && ((!newItem.equals("-Select-"))))
				{
					String itemToUpdate = (String)myCBox.getSelectedItem();
					db_status = myFrame.update(newItem, itemToUpdate, tName);
					if(db_status)
					{
						myCBox.removeItem(itemToUpdate);
						myCBox.addItem(newItem);
						btn_south.setText(itemToUpdate+" updated as "+newItem+"..");
					}
					else
					btn_south.setText("Item NOT updated..");
				}
			}
			else
			{
				btn_south.setText("CAUTION: Select an item from the List to update or insert an appropriate "+tName+"..");
			}
		}
		else if(btnLabel == "Delete")
		{
			if((myCBox.getSelectedIndex() != -1) && (!myCBox.getSelectedItem().equals("-Select-")))
			{
				String itemToDelete = (String)myCBox.getSelectedItem();
				db_status = myFrame.delete(itemToDelete, tName);
				if(db_status)
				{
					myCBox.removeItem(itemToDelete);
					btn_south.setText(itemToDelete+" deleted..");
				}
				else
				btn_south.setText(itemToDelete +" NOT deleted..");				
			}
			else
			{
				btn_south.setText("CAUTION: Select an item from the List to delete..");
			}
		}
	}
	static void addRadioButton(final String tableName, String label)
	{
		rbtn = new JRadioButton(label);
		group.add(rbtn);
		nextPanel.add(rbtn);
		rbtn.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					page2 = new myFrame2(tableName);
                    page2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    page2.setVisible(true);					
					Page1frame.setVisible(false);
				}
			}
		);
	}
	static void viewPage1(){
		page2.setVisible(false);
		Page1frame.setVisible(true);
	}
	static JPanel nextPanel;
	static JButton btnGo = new JButton("Select the parameter by which you would like to generate TimeTable : ");
	static ButtonGroup group = new ButtonGroup();
	static JRadioButton rbtn;
	JComboBox myCBox;
	static JButton btnHead = new JButton("Welcome to TimeTable Software");
	String tName;
	static JButton btn_south;
	protected JPanel myInnerPanel = new JPanel();
	JButton btnInsert;
	JButton btnUpdate;
	JButton btnDelete;
	JTextField tf1;
	static myFrame Page1frame;
	static myFrame2 page2;
	static
	{
		btn_south = new JButton("Welcome");
		btn_south.setEnabled(false);
		nextPanel = new JPanel();
		//nextPanel.add(btnGo); 
		page1rowTypeA.addRadioButton("batch", "Batches");
		page1rowTypeA.addRadioButton("room", "Rooms");
		page1rowTypeA.addRadioButton("teacher", "Teachers");
		btnHead.setEnabled(false);
		btnGo.setEnabled(false);
	}
}