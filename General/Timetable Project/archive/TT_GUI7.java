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
		
                JPanel TTPanel = new JPanel(); //New Panel to be addded to frame
		page1rowA Trow = new page1rowA(TTPanel, "Teachers: ", new String[] {
                        "Prateek Bhatia",
                        "Ajay Kumar",
                        "Varinder Singh"}, 25);

		page1rowA Crow = new page1rowA(TTPanel, "Courses: ", new String[] {
			"Computer Architecture",
			"Operating Systems"}, 60);

		page1rowB Grow = new page1rowB(TTPanel, "Groups: ", new String[] {
                        "COE",
                        "COE_G1","COE_G2",
                        "COE_T1","COE_T2","COE_T3","COE_T4","COE_T5","COE_T6"}, 95);

		page1rowB Rrow = new page1rowB(TTPanel, "Rooms: ", new String[] {
                        "F101",
                        "F102",
                        "D115",
						"D116"}, 130);

	        add(TTPanel, BorderLayout.CENTER);//adds TTPanel to the frame
//                Action1 InsertAction = new Action1();//                myCBox.addActionListener(actionTaker);              
//                btnTEdit.addActionListener(InsertAction);
        }
	
        private static final int DEFAULT_WIDTH  = 400;
        private static final int DEFAULT_HEIGHT = 400;
                
}
/*class Action1 implements ActionListener{
        public void actionPerformed(ActionEvent event)
	{
		
                System.out.println("Event generated(comboBox)");
		String input1 = tf1.getText();
                        
                String input2= tf2.getText();
		myCBox.addItem(input1+" "+input2);
	}
}*/
class page1rowA{

	page1rowA(JPanel myPanel, String LabelName,String[] CBoxOptions, int posY){
		
        JLabel myLabel = new JLabel(LabelName);
        JComboBox myCBox=new JComboBox(CBoxOptions);
		JPanel myInnerPanel = new JPanel();
		tf1 = new JTextField("Insert "+LabelName);
//		tf2 = new JTextField("input2..");
		JButton btnTEdit = new JButton("Insert");//Insert Delete

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
	public JTextField tf1;
//	public JTextField tf2;
}
class page1rowB{

	page1rowB(JPanel myPanel, String LabelName,String[] CBoxOptions, int posY){
		
        JLabel myLabel = new JLabel(LabelName);
        JComboBox myCBox=new JComboBox(CBoxOptions);
		JPanel myInnerPanel = new JPanel();
		tf1 = new JTextField("Insert "+LabelName);
//		tf2 = new JTextField("input2..");
		JButton btnTEdit = new JButton("Insert");//Insert Delete

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
	public JTextField tf1;
//	public JTextField tf2;
}

/*class rowFormat{
        public rowFormat(String name, String[] dropDownOptions){



//                ActionListener listener = new Dummy();

                //construct components///////////////
                JLabel faceLabel = new JLabel(name+": ");
		
                face=new JComboBox(dropDownOptions);

                face.addActionListener(new ActionListener(){
                        public void actionPerformed(ActionEvent event){
                        System.out.println("Event generated(comboBox)");
                        }
                });              //////////////////
	}               
        private JComboBox face;
}
*/
