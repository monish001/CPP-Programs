import java.awt.event.ActionEvent;
import java.awt.Font;
import java.awt.GridBagLayout;
import java.awt.event.ActionListener;
import javax.swing.JLabel;

import javax.swing.JPanel;
import javax.swing.JButton;
class Panel1Timetable extends JPanel {

    public Panel1Timetable(final Frame1Timetable frame) {

        DatabaseOperations db = new DatabaseOperations();
        OperationsPanel teacherLine = new OperationsPanel(frame, "TEACHER", db.getDistinctListFromDataBase("TEACHER", "id"));
        OperationsPanel courseLine = new OperationsPanel(frame, "COURSE", db.getDistinctListFromDataBase("course", "id"));
        OperationsPanel sectionLine = new OperationsPanel(frame, "BATCH", db.getDistinctListFromDataBase("BATCH", "id"));
        OperationsPanel roomLine = new OperationsPanel(frame, "ROOM", db.getDistinctListFromDataBase("room", "id"));

        JLabel headingFrame1Label = new JLabel("Timetable Scheduling Software");
        headingFrame1Label.setFont(new Font(null, Font.BOLD, 25));

        JPanel exitPanel = new JPanel();//move to next page or exit;
        JButton exitButton = new JButton("EXIT");
        exitButton.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        JButton nextButton = new JButton("NEXT");
        nextButton.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                frame.actionNextPanel1();
            }
        });
        exitPanel.add(nextButton);
        exitPanel.add(exitButton);

        this.setLayout(new GridBagLayout());//INNER PANEL
        this.add(headingFrame1Label, new GBC(0, 0));
        this.add(teacherLine, new GBC(1, 0));//ADDING TO INNER PANEL
        this.add(courseLine, new GBC(2, 0));//ADDING TO INNER PANEL
        this.add(sectionLine, new GBC(3, 0));//ADDING TO INNER PANEL
        this.add(roomLine, new GBC(4, 0));//ADDING TO INNER PANEL
        this.add(exitPanel, new GBC(5, 0));

    //add components to the outer panel and further add outer panel to the content pane.

    }
}
