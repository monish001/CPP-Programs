import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import javax.swing.UIManager;
import javax.swing.SwingUtilities;
import javax.swing.JLabel;
import javax.swing.JFrame;
import javax.swing.JDialog;

import javax.swing.JPanel;
import javax.swing.JButton;
class AboutDialog extends JDialog {

    public AboutDialog(JFrame owner) {
        super(owner, "About Timetable Scheduling Software", true);
        //Look and feel
        try {
            UIManager.LookAndFeelInfo[] infos = UIManager.getInstalledLookAndFeels();
            UIManager.setLookAndFeel(infos[0].getClassName());
        } catch (Exception ex) {
            System.out.println("UI myerror");
        }
        SwingUtilities.updateComponentTreeUI(AboutDialog.this);
        //This line starts after some blank space at left
        add(new JLabel("<html><h2>Timetable Scheduling Software</h2><hr><span style=\"padding-left:2px\">By Monish Gupta<br/>3rd year<br/>BE CSE<br/>Thapar University</span><hr></html>"),
                BorderLayout.CENTER);
        JPanel panel = new JPanel();
        JButton ok = new JButton("Ok");
        ok.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                setVisible(false);
            }
        });
        panel.add(ok);
        add(panel, BorderLayout.SOUTH);
        pack();
    }
}

