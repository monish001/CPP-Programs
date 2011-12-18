import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class PanelTest extends JFrame
{
        public static void main(String args[])
        {
			PanelTest p1 = new PanelTest();
            p1.setVisible(true);
		}
		PanelTest()
		{
            JPanel panel = new JPanel(new GridLayout(2,0));
			(this.myPanel[0]).add(new JButton("hello1"));
            panel.add(myPanel[0]);
            (this.myPanel[1]).add(new JButton("hello1"));
            panel.add(myPanel[1]);
			add(panel, BorderLayout.CENTER);
            pack();
        }
        JPanel[] myPanel = new JPanel[2];
}