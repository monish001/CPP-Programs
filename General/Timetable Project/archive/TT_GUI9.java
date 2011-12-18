//All four rows (without Event Listeners ) created and saved in TT_GUI7.java
//TT_GUI9.java: Draw GUI of Page1 and initialises the CBoxes from database tables.
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
	Statement stmt;
	ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
	String qry;
	int qry_op;
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
			System.out.println(e.toString());
		}		
		Scanner in = new Scanner(System.in);

		JPanel TTPanel = new JPanel(); //New Panel to be addded to frame
		
		page1rowTypeA Trow = new page1rowTypeA(TTPanel, "Batch", initialOptions("batch"), 25);

		page1rowTypeA Crow = new page1rowTypeA(TTPanel, "Course", initialOptions("course"), 60);

		page1rowTypeA Grow = new page1rowTypeA(TTPanel, "Room", initialOptions("room"), 95);

		page1rowTypeA Rrow = new page1rowTypeA(TTPanel, "teacher", initialOptions("teacher"), 130);

	    add(TTPanel, BorderLayout.CENTER);//adds TTPanel to the frame
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
			System.out.println(e.toString());
		}			
		return (CBoxOptions);
	}
	public void insert(String itemToInsert, String tName)
	{
		qry = "Insert into "+tName+" values("+itemToInsert+")";
		try{
			qry_op = stmt.executeUpdate(qry);
		}
		catch(SQLException e)
		{
			System.out.println(e.toString());
		}		
		if(qry_op == 1)
			System.out.println(itemToInsert+" inserted in "+tName);
	}
	public void delete(String itemToDelete, String tName)
	{
		qry = "delete from "+tName+" where id = "+itemToDelete;
		try
		{
			qry_op = stmt.executeUpdate(qry);
		}
		catch(SQLException e)
		{
			System.out.println(e.toString());
		}		
		if(qry_op == 1)
			System.out.println(itemToDelete+" Deleted in "+tName);
	}
	public void update(String oldItem, String newItem, String tName)
	{
		qry = "Update "+tName+" set id = "+newItem+" where id = "+oldItem;
		try
		{
			qry_op = stmt.executeUpdate(qry);
		}
		catch(SQLException e)
		{
			System.out.println(e.toString());
		}		
		if(qry_op == 1)
			System.out.println("Item "+oldItem+" Updated to "+newItem+" in "+tName);
	}
    private static final int DEFAULT_WIDTH  = 400;
    private static final int DEFAULT_HEIGHT = 400;
}/*
class Action1 implements ActionListener{
        public void actionPerformed(ActionEvent event)
	{
		
                System.out.println("Event generated(comboBox)");
		String input1 = tf1.getText();
                        
                String input2= tf2.getText();
		myCBox.addItem(input1+" "+input2);
	}
}*/
class page1rowTypeA{

	page1rowTypeA(JPanel myPanel, String LabelName,String[] CBoxOptions, int posY){
		
        JLabel myLabel = new JLabel(LabelName);
        JComboBox myCBox=new JComboBox(CBoxOptions);

		tf1 = new JTextField("Insert "+LabelName);
//		tf2 = new JTextField("input2..");
		btnTEdit = new JButton("Insert");//Insert Delete
		
		addTextfieldsToMyInnerPanel();
        myInnerPanel.add(btnTEdit);//add btnTEdit to myInnerPanel			
		JPanel OPanel = new JPanel();
        OPanel.add(myLabel);// myLabel.setBounds(25, posY, 70, 30);//add faceLabel to OPanel
        OPanel.add(myCBox); //myCBox.setBounds(100, posY, 70, 30);//add faceCBox to OPanel 
		OPanel.add(myInnerPanel);// myInnerPanel.setBounds(175, posY, 70, 30);//add inner panel to OPanel
		myPanel.add(OPanel);//add OPanel to myPanel
		//OPanel.setBounds(25, posY, 40, 300);
	}
	void addTextfieldsToMyInnerPanel(){
        myInnerPanel.add(tf1);//add tf1 to myInnerPanel
//        myInnerPanel.add(tf2);//add tf2 to myInnerPanel	
	}
	protected JPanel myInnerPanel = new JPanel();
	public JButton btnTEdit;
	public JTextField tf1;
//	public JTextField tf2;
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

