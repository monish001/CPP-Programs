//File: GUI_QPDownloader.java
/*TODO

*/
import javax.swing.*;
import java.awt.*;
public class GUI_QPDownloader{
	GUI_QPDownloader(){
		frame = new JFrame("TU Question Papers Downloader");
		frame.setSize(250, 250);
		frame.setLocation(300,200);
		frame.getContentPane().add(BorderLayout.CENTER, new JTextArea(10, 40));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	public static void main(String[] args){
		GUI_QPDownloader g = new GUI_QPDownloader();
	}
	JFrame frame;
}