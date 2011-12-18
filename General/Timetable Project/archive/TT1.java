//TT1.java : an empty frame.
import java.sql.*;
//import javax.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class TT1{
	public static void main(String[] args)
	{
		EventQueue.invokeLater(new Runnable()
		{
            public void run(){
					myFrame2 frame=new myFrame2();
                    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    frame.setVisible(true);
            }
        });
	}
}
class myFrame2 extends JFrame{
    myFrame2()
	{
		//this.tName = tName;
		System.out.println("Page2 working.");
        setTitle("Administrator Screen");
        setSize(600, 400);
		setResizable(false); 
		JButton btnBack = new JButton("Back");
		btnBack.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					page1rowTypeA.viewPage1();
				}
			}
		);
		add(btnBack);
    }
}