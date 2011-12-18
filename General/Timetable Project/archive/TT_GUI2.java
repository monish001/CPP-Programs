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

                String LabelName = "Teachers: ";
                String[] CBoxOptions={
                        "Prateek Bhatia",
                        "Ajay Kumar",
                        "Varinder Singh"};

                JLabel myLabel = new JLabel(LabelName);
                myCBox=new JComboBox(CBoxOptions);
		JPanel myInnerPanel = new JPanel();
		tf1 = new JTextField("input1..");
		tf2 = new JTextField("input2..");
		JButton btnTEdit = new JButton("Insert");//Insert Delete
                myInnerPanel.add(tf1);//add tf1 to myInnerPanel
                myInnerPanel.add(tf2);//add tf2 to myInnerPanel
                myInnerPanel.add(btnTEdit);//add btnTEdit to myInnerPanel			
		
                JPanel TTPanel = new JPanel(); //New Panel
                TTPanel.add(myLabel);//add faceLabel to TTPanel
                TTPanel.add(myCBox);//add faceCBox to TTPanel 
		TTPanel.add(myInnerPanel);//add inner panel to TTPanel
                add(TTPanel, BorderLayout.WEST);//adds TTPanel to the frame
                Action1 InsertAction = new Action1();//                myCBox.addActionListener(actionTaker);              
                btnTEdit.addActionListener(InsertAction);
        }
	class Action1 implements ActionListener{
                public void actionPerformed(ActionEvent event)
		{
                        System.out.println("Event generated(comboBox)");
			String input1 = tf1.getText();
                        
                        String input2= tf2.getText();
			myCBox.addItem(input1+" "+input2);
                      
                }
        }
        public JComboBox myCBox;
//	JPanel myInnerPanel = new JPanel();
	public JTextField tf1;
	public JTextField tf2;
	
        private static final int DEFAULT_WIDTH  = 400;
        private static final int DEFAULT_HEIGHT = 400;
                
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
