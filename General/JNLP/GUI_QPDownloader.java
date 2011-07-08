//File: GUI_QPDownloader.java
/*TODO

*/

import javax.swing.*;
import java.awt.*;

public class GUI_QPDownloader extends JFrame{
	void createGUI(){
		add((new JPanel()).add(new JButton("Hello")));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		pack();
		setVisible(true);
	}
	public static void main(String[] args){
		GUI_QPDownloader g = new GUI_QPDownloader();
		g.createGUI();
	}
	JFrame frame;
}