//All four rows (without Event Listeners ) created and saved in TT_GUI7.java
//TT_GUI9.java: Draw GUI of Page1 and initialises the CBoxes from database tables.
//TT_GUI10.java: TT_GUI9.java + unsuccessful operations in database + working in cboxes
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
	//JdbcConnection myCon;
	//Connection con;
	static Statement stmt;
	static ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
	static String qry;
	static int qry_op;
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
		
		page1rowTypeA Trow = new page1rowTypeA(TTPanel, "Batch", initialOptions("batch"), 25);

		page1rowTypeA Crow = new page1rowTypeA(TTPanel, "Course", initialOptions("course"), 60);

		page1rowTypeA Grow = new page1rowTypeA(TTPanel, "Room", initialOptions("room"), 95);

		page1rowTypeA Rrow = new page1rowTypeA(TTPanel, "teacher", initialOptions("teacher"), 130);

	    add(TTPanel, BorderLayout.CENTER);//adds TTPanel to the frame
		add(page1rowTypeA.tf_south, BorderLayout.SOUTH);
    }
	public String[] initialOptions( String tname )
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
	public static void insert(String itemToInsert, String tName)
	{
		qry = "Insert into "+tName+" values("+itemToInsert+")";
		try{
			qry_op = stmt.executeUpdate(qry);
		}
		catch(SQLException e)
		{
			System.out.println("Error in static insert() "+e.toString());
		}		
		if(qry_op == 1)
			System.out.println(itemToInsert+" inserted in "+tName);
	}
	public static void delete(String itemToDelete, String tName)
	{
		qry = "delete from "+tName+" where id = "+itemToDelete;
		try
		{
			qry_op = stmt.executeUpdate(qry);
		}
		catch(SQLException e)
		{
			System.out.println("Error in static delete() "+e.toString());
		}		
		if(qry_op == 1)
			System.out.println(itemToDelete+" Deleted in "+tName);
	}
	public static void update(String oldItem, String newItem, String tName)
	{
		qry = "Update "+tName+" set id = "+newItem+" where id = "+oldItem;
		try
		{
			qry_op = stmt.executeUpdate(qry);
		}
		catch(SQLException e)
		{
			System.out.println("Error in static update() "+e.toString());
		}		
		if(qry_op == 1)
			System.out.println("Item "+oldItem+" Updated to "+newItem+" in "+tName);
	}
    private static final int DEFAULT_WIDTH  = 400;
    private static final int DEFAULT_HEIGHT = 400;
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
		addTextfieldsToMyInnerPanel();
        myInnerPanel.add(btnInsert);//add btn to myInnerPanel			
        myInnerPanel.add(btnUpdate);//add btn to myInnerPanel			
        myInnerPanel.add(btnDelete);//add btn to myInnerPanel			
		JPanel OPanel = new JPanel();
        OPanel.add(myLabel);// myLabel.setBounds(25, posY, 70, 30);//add faceLabel to OPanel
        OPanel.add(myCBox); //myCBox.setBounds(100, posY, 70, 30);//add faceCBox to OPanel 
		OPanel.add(myInnerPanel);// myInnerPanel.setBounds(175, posY, 70, 30);//add inner panel to OPanel
		myPanel.add(OPanel);//add OPanel to myPanel
		//OPanel.setBounds(25, posY, 40, 300);
	}
	void addTextfieldsToMyInnerPanel(){
        myInnerPanel.add(tf1);//add tf1 to myInnerPanel
	}
	public void actionPerformed(ActionEvent event)
	{
		String btnLabel = event.getActionCommand();
		if(btnLabel == "Insert")
		{
			String itemToInsert = tf1.getText();
			myFrame.insert(itemToInsert, tName);
			myCBox.addItem(itemToInsert);
			tf_south.setText(itemToInsert +" inserted..");
		}
		else if(btnLabel == "Update")
		{	
			String newItem = tf1.getText();		
			if(myCBox.getSelectedIndex() != -1)
			{
				String itemToUpdate = (String)myCBox.getSelectedItem();
				myFrame.update(newItem, itemToUpdate, tName);
				myCBox.removeItem(itemToUpdate);
				myCBox.addItem(newItem);
				tf_south.setText(itemToUpdate+" updated as "+newItem+"..");
			}
			else
			{
				tf_south.setText("CAUTION: Select an item from the List to update..");
			}
		}
		else if(btnLabel == "Delete")
		{
			
			if(myCBox.getSelectedIndex() != -1)
			{
				String itemToDelete = (String)myCBox.getSelectedItem();
				myFrame.delete(itemToDelete, tName);
				myCBox.removeItem(itemToDelete);
				tf_south.setText(itemToDelete+" deleted..");			
			}
			else
			{
				tf_south.setText("CAUTION: Select an item from the List to delete..");
			}
		}
	}
	JComboBox myCBox;
	String tName;
	static JTextField tf_south = new JTextField("Welcome");
	protected JPanel myInnerPanel = new JPanel();
	JButton btnInsert;
	JButton btnUpdate;
	JButton btnDelete;
	JTextField tf1;
}/*
class page1rowTypeB extends page1rowTypeA{
	page1rowTypeB(JPanel myPanel, String LabelName,String[] CBoxOptions, int posY)
	{
		super(myPanel, LabelName, CBoxOptions, posY);
	}
	void addTextfieldsToMyInnerPanel(){
        myInnerPanel.add(tf1);//add tf1 to myInnerPanel
        myInnerPanel.add(tf2);//add tf2 to myInnerPanel	
	}

	public JTextField tf2;
	
}*/

/*class page1rowTypeB{

	page1rowTypeB(JPanel myPanel, String LabelName,String[] CBoxOptions, int posY){
		
        JLabel myLabel = new JLabel(LabelName);
        JComboBox myCBox=new JComboBox(CBoxOptions);
		JPanel myInnerPanel = new JPanel();
		tf1 = new JTextField("Insert "+LabelName);
//		tf2 = new JTextField("input2..");
		btnTEdit = new JButton("Insert");//Insert Delete

        myInnerPanel.add(tf1);//add tf1 to myInnerPanel
//        myInnerPanel.add(tf2);//add tf2 to myInnerPanel
        myInnerPanel.add(btnTEdit);//add btnTEdit to myInnerPanel			
		JPanel OPanel = new JPanel();
        OPanel.add(myLabel);// myLabel.setBounds(25, posY, 70, 30);//add faceLabel to OPanel
        OPanel.add(myCBox); //myCBox.setBounds(100, posY, 70, 30);//add faceCBox to OPanel 
		OPanel.add(myInnerPanel);// myInnerPanel.setBounds(175, posY, 70, 30);//add inner panel to OPanel
		myPanel.add(OPanel);//add OPanel to myPanel
		//OPanel.setBounds(25, posY, 40, 300);
	}
	JButton btnTEdit;
	public JTextField tf1;
//	public JTextField tf2;
}*/

