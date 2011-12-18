//All four rows (without Event Listeners ) created and saved in TT_GUI7.java
//TT_GUI9.java: Draw GUI of Page1 and initialises the CBoxes from database tables.
//TT_GUI10.java: TT_GUI9.java + unsuccessful operations in database + working in cboxes
//TT_GUI.11.java: prev + successful operations in database + working in cboxes + consistency assured 
//				 + tf an south for conformation msgs replaced by button+ addTextfieldsToMyInnerPanel() replaced by its definition.
import java.sql.*;
//import javax.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class TT_GUI{
public static void main(String[] args){
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
	public static String[] initialOptions( String tname )
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
	}
    myFrame(){
        setTitle("Administrator Screen");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
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
		
		page1rowTypeA Trow = new page1rowTypeA(TTPanel, "batch", myFrame.initialOptions("batch"), 25);

		page1rowTypeA Crow = new page1rowTypeA(TTPanel, "course", myFrame.initialOptions("course"), 60);

		page1rowTypeA Grow = new page1rowTypeA(TTPanel, "room", myFrame.initialOptions("room"), 95);

		page1rowTypeA Rrow = new page1rowTypeA(TTPanel, "teacher", myFrame.initialOptions("teacher"), 130);

	    add(TTPanel, BorderLayout.CENTER);//adds TTPanel to the frame
		add(page1rowTypeA.btn_south, BorderLayout.SOUTH);
		//pack();
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
    private static final int DEFAULT_WIDTH  = 400;
    private static final int DEFAULT_HEIGHT = 400;
	static Statement stmt;
	static ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
	static String qry;
	//static int qry_op;
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
			db_status = myFrame.insert(itemToInsert, tName);
			if(db_status)
			{
				myCBox.addItem(itemToInsert);
				btn_south.setText(itemToInsert +" inserted..");
			}
			else
				btn_south.setText(itemToInsert +"NOT inserted..");
		}
		else if(btnLabel == "Update")
		{	
			String newItem = tf1.getText();		
			if(myCBox.getSelectedIndex() != -1)
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
				btn_south.setText(itemToInsert +"NOT inserted..");
			}
			else
			{
				btn_south.setText("CAUTION: Select an item from the List to update..");
			}
		}
		else if(btnLabel == "Delete")
		{
			
			if(myCBox.getSelectedIndex() != -1)
			{
				String itemToDelete = (String)myCBox.getSelectedItem();
				db_status = myFrame.delete(itemToDelete, tName);
				if(db_status)
				{
					myCBox.removeItem(itemToDelete);
					btn_south.setText(itemToDelete+" deleted..");
				}
				else
				btn_south.setText(itemToInsert +"NOT inserted..");				
			}
			else
			{
				btn_south.setText("CAUTION: Select an item from the List to delete..");
			}
		}
	}
	JComboBox myCBox;
	String tName;
	static JButton btn_south;
	static
	{
		btn_south = new JButton("Welcome");
		btn_south.setEnabled(false);
		
	}
	protected JPanel myInnerPanel = new JPanel();
	JButton btnInsert;
	JButton btnUpdate;
	JButton btnDelete;
	JTextField tf1;
}