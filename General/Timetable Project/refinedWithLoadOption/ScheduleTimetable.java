/*ScheduleTimetable.java*/
//import javax.swing.JOptionPane;
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

import javax.swing.JPanel;

class ScheduleTimetable {

    public static void main(String args[]) {
        //Frame1Timetable frame;
        EventQueue.invokeLater(new Runnable() {

            public void run() {
                Frame1Timetable framePage1 = new Frame1Timetable();
                framePage1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                framePage1.setTitle("Timetable Scheduling Software: Administrator Screen");

                framePage1.setVisible(true);
            }
        });
    }
}

class Frame1Timetable extends JFrame {// implements ActionListener

    Frame1Timetable() {
        dialog = new AboutDialog(this);
        //Look and feel
        try {
            UIManager.LookAndFeelInfo[] infos = UIManager.getInstalledLookAndFeels();
            UIManager.setLookAndFeel(infos[0].getClassName());
        } catch (Exception ex) {
            System.out.println("UI myerror");
        }
        SwingUtilities.updateComponentTreeUI(Frame1Timetable.this);
        //this.setExtendedState(MAXIMIZED_BOTH);
        //this.setResizable(false);
        panel1Timetable = new Panel1Timetable(this);
        panel2Timetable = new Panel2Timetable(this);

////////////////////////////menu bar starts//////////////////
        this.setJMenuBar((new TimetableJMenuBar(dialog)).menuBar());
//////////////////////////menu bar ends//////////////////

        textField = new JTextField("", JTextField.CENTER);
        textField.setEditable(false);
        textField.setBackground(Color.white);

        frontPageBorderLayoutPanel = new JPanel(new BorderLayout());//OUTER PANEL
        this.addPanel1Timetable();
        frontPageBorderLayoutPanel.add(textField, BorderLayout.SOUTH);//OUTER PANEL ADDS INNER TO ITS CENTER

        this.getContentPane().add(frontPageBorderLayoutPanel);//ADDING OUTER PANEL TO FRAME'S CONTENT PANE.
        this.pack();
    }

    Panel1Timetable addPanel1Timetable() {//make return type void
        textField.setText("Monish Gupta welcomes you to the Timetable Scheduling software.");
        frontPageBorderLayoutPanel.add(panel1Timetable, BorderLayout.CENTER);//OUTER PANEL ADDS INNER TO ITS CENTER
        frontPageBorderLayoutPanel.add(textField, BorderLayout.SOUTH);//OUTER PANEL ADDS INNER TO ITS CENTER
        return panel1Timetable;

    }

    Panel2Timetable addPanel2Timetable() {
        textField.setText("Select any section/teacher/room to schedule or view the timetable.");
        //panel2Timetable = new Panel2Timetable(this);
        frontPageBorderLayoutPanel.add(panel2Timetable, BorderLayout.CENTER);//OUTER PANEL ADDS INNER TO ITS CENTER
        frontPageBorderLayoutPanel.add(textField, BorderLayout.SOUTH);//OUTER PANEL ADDS INNER TO ITS CENTER
        return panel2Timetable;
    }

    void actionNextPanel1() {
        frontPageBorderLayoutPanel.removeAll();
        this.addPanel2Timetable();
        this.pack();
    }

    void actionBackPanel2() {
        frontPageBorderLayoutPanel.removeAll();
        this.addPanel1Timetable();
        this.pack();
    }

    void repaintPanel2Timetable(String tableName, String value) {
        (panel2Timetable.centerPanel).removeAll();//(panel2Timetable.particularTimetable);
        panel2Timetable.particularTimetable = new ParticularTimetable(this, tableName, value);
        (panel2Timetable.centerPanel).add(panel2Timetable.particularTimetable);
        this.validateTree();
        this.setExtendedState(MAXIMIZED_BOTH);
    }

    void setFooterText(String message) {
        textField.setText(message);
    }
    Panel1Timetable panel1Timetable;
    Panel2Timetable panel2Timetable;
    JPanel frontPageBorderLayoutPanel;
    JDialog dialog;
    public JTextField textField;
}
/*class ChooseTimetableDialog extends JDialog{
public ChooseTimetableDialog(JFrame owner){
super("Choose excel sheet containing the timetable, degree, year");

}
}*/

