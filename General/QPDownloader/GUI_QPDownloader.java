/*
 * GUI_QPDownloader.java
 *
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GUI_QPDownloader extends JFrame{
    JButton dl_btn = new JButton("Download Selected");
	JTable table;
	
    public GUI_QPDownloader(String name) {
        super(name);
        setResizable(false);
    }

    public void addComponentsToPane(final Container pane) {
        final JPanel compsToExperiment = new JPanel();
		QPDownloader qpdown = new QPDownloader();
		
        compsToExperiment.add(table = new JTable(SeasonPage.courses.size(), qpdown.seasonPagesInfo.size()));
		
		
		
		//controls
        JPanel controls = new JPanel();
		dl_btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
				//do stuff
            }
        });
        controls.add(dl_btn);

        pane.add(compsToExperiment, BorderLayout.NORTH);
        pane.add(new JSeparator(), BorderLayout.CENTER);
        pane.add(controls, BorderLayout.SOUTH);
    }

	public static void main(String[] args){
        /* Use an appropriate Look and Feel */
        try {
            //UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
        } catch (UnsupportedLookAndFeelException ex) {
            ex.printStackTrace();
        } catch (IllegalAccessException ex) {
            ex.printStackTrace();
        } catch (InstantiationException ex) {
            ex.printStackTrace();
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        }
        /* Turn off metal's use of bold fonts */
        UIManager.put("swing.boldMetal", Boolean.FALSE);
        
        //Schedule a job for the event dispatch thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
				//Create and set up the window.
				GUI_QPDownloader frame = new GUI_QPDownloader("TU QPDownloader");
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				//Set up the content pane.
				frame.addComponentsToPane(frame.getContentPane());
				//Display the window.
				frame.pack();
				frame.setVisible(true);
            }
        });
	}
}