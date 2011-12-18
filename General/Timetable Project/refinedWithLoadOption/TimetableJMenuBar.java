import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JMenu;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.UIManager;
import javax.swing.SwingUtilities;
import javax.swing.JTextField;
import javax.swing.JFrame;
import javax.swing.JDialog;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JMenu;
import javax.swing.JFileChooser;
import javax.swing.JPanel;
class TimetableJMenuBar extends JMenuBar{
	TimetableJMenuBar(final JDialog dialog){
		//file 
        JMenu fileMenu = new JMenu("File");
        fileMenu.setMnemonic('F');
//file>exit
        JMenuItem exitMenuItem = fileMenu.add("Exit");
        exitMenuItem.setMnemonic('X');
        exitMenuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
//file>load
        JMenuItem loadMenuItem = fileMenu.add("Load");
        loadMenuItem.setMnemonic('L');
        loadMenuItem.addActionListener(new FileOpenListener());
        /*loadMenuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                String fileLocation = "../XlsToDB/UG-I.xls", degree = "BE";
                String year = "1", lineIndexOfSections = "6";
                try {
                    XlsToCmdReadVertically.main(new String[]{fileLocation, degree, year, lineIndexOfSections});
                } catch (NullPointerException ex) {
                    System.out.println("ex.toString()");
                    Logger.getLogger(Frame1Timetable.class.getName()).log(Level.SEVERE, null, ex);
                } catch (FileNotFoundException ex) {
                    System.out.println("ex.toString()");
                    Logger.getLogger(Frame1Timetable.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    System.out.println("ex.toString()");
                    Logger.getLogger(Frame1Timetable.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });*/
//edit
        JMenu editMenu = new JMenu("Edit");
        editMenu.setMnemonic('E');
//edit>Constraints
        JMenuItem constraintsMenuItem = editMenu.add("Constraints");
        constraintsMenuItem.setMnemonic('C');
        constraintsMenuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //throw new UnsupportedOperationException("Not supported yet.");
            }
        });
//help
        JMenu helpMenu = new JMenu("Help");
        helpMenu.setMnemonic('H');
//help>about
        JMenuItem aboutMenuItem = helpMenu.add("About");
        aboutMenuItem.setMnemonic('A');
        aboutMenuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                dialog.setVisible(true);
            }
        });
//help>documentation
        JMenuItem docMenuItem = helpMenu.add("Documentation");
        docMenuItem.setMnemonic('D');
        docMenuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                /*try {
                String command = "C:/Program Files/Adobe/Reader 8.0/Reader/AcroRd32.exe reportFull.pdf";
                Process process = Runtime.getRuntime().exec(command);
                process.waitFor();
                System.out.println("Executing command: " + command + "\n" + process.exitValue());
                } catch(Exception ex) {
                System.out.println(ex.toString());
                }*/
            }
        });
        this.add(fileMenu);
        this.add(editMenu);
        this.add(helpMenu);
        /*
        JMenuBar menuBar = new JMenuBar();
        menuBar.add(fileMenu);
        menuBar.add(editMenu);
        menuBar.add(helpMenu);
        this.setJMenuBar(menuBar);*/
	}
/*	class FileOpenListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event){
				chooser.setCurrentDirectory(new File("."));
				
				// show file  chooser dialog
				int result = chooser.showOpenDialog(Frame1Timetable.this);
				
				// if 
			}
		}*/
	private JFileChooser chooser;
	JMenuBar menuBar(){return this;}
}
