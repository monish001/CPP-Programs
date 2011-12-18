//All four rows (without Event Listeners ) created and saved in TT_GUI7.java
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
        myFrame(){
                setTitle("Administrator Screen");
                setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
				JdbcConnection myCon = new JdbcConnection();
				Connection con=c.conn();//Get a Connection object
				
				Scanner in=new Scanner(System.in);
		Statement stmt = con.createStatement();//Get a Statement object
        	ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
		String qry=new String("select * from batch");//Execute queries and/or updates
		rset=stmt.executeQuery(qry);
		//System.out.println("Name\tNull?\tType");
		while(rset.next())
		{
			System.out.println(rset.getString(1));
		}
			JPanel TTPanel = new JPanel(); //New Panel to be addded to frame
		page1rowTypeA Trow = new page1rowTypeA(TTPanel, "Teachers: ", new String[] {
                        "Prateek Bhatia",
                        "Ajay Kumar",
                        "Varinder Singh"}, 25);

		page1rowTypeA Crow = new page1rowTypeA(TTPanel, "Courses: ", new String[] {
			"Computer Architecture",
			"Operating Systems"}, 60);

		page1rowTypeA Grow = new page1rowTypeA(TTPanel, "Groups: ", new String[] {
                        "COE",
                        "COE_G1","COE_G2",
                        "COE_T1","COE_T2","COE_T3","COE_T4","COE_T5","COE_T6"}, 95);

		page1rowTypeA Rrow = new page1rowTypeA(TTPanel, "Rooms: ", new String[] {
                        "F101", "F102", "D115",	"D116"}, 130);

	        add(TTPanel, BorderLayout.CENTER);//adds TTPanel to the frame
//                Action1 InsertAction = new Action1();//                myCBox.addActionListener(actionTaker);              
//                btnTEdit.addActionListener(InsertAction);
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

