import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import javax.swing.JScrollPane;
import javax.swing.border.Border;
import javax.swing.BorderFactory;

import javax.swing.JPanel;
import javax.swing.JComboBox;
import javax.swing.JButton;
class Panel2Timetable extends JPanel {

    public Panel2Timetable(final Frame1Timetable frame) {
//contents of north border
        DatabaseOperations db = new DatabaseOperations();

        Border etched = BorderFactory.createEtchedBorder();
        if (etched == null) {
            System.out.println("etched is null");
            System.exit(0);
        }

        final JComboBox sectionComboBox = new JComboBox(db.getDistinctListFromDataBase("BATCH", "ID"));
        final JComboBox teacherComboBox = new JComboBox(db.getDistinctListFromDataBase("TEACHER", "ID"));
        final JComboBox roomComboBox = new JComboBox(db.getDistinctListFromDataBase("ROOM", "ID"));
        Border titledSection = BorderFactory.createTitledBorder(etched, "BATCH:");
        sectionComboBox.setBorder(titledSection);
        sectionComboBox.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                String section = (String) sectionComboBox.getSelectedItem();
                if (section.charAt(0) == '-') {//(section.equals("-SELECT-"))
                    frame.setFooterText("Select appropriate option.");
                } else//particularTimetable()
                {
                    //frame.setFooterText("Loading... Please Wait");
                    roomComboBox.setSelectedIndex(0);
                    //frame.setFooterText("Loading... Please Wait");
                    teacherComboBox.setSelectedIndex(0);
                    frame.setFooterText("Loading... Please Wait");
                    frame.repaintPanel2Timetable("BATCH", section);
                    frame.setFooterText("Timetable for BATCH: " + section + " loaded.");
                }
            }
        });

        Border titledTeacher = BorderFactory.createTitledBorder(etched, "TEACHER:");
        teacherComboBox.setBorder(titledTeacher);
        teacherComboBox.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                String teacher = (String) teacherComboBox.getSelectedItem();
                if (teacher.charAt(0) == '-') {
                    frame.setFooterText("Select appropriate option.");
                } else//particularTimetable()
                {
                    roomComboBox.setSelectedIndex(0);
                    sectionComboBox.setSelectedIndex(0);
                    frame.setFooterText("Loading... Please Wait");
                    frame.repaintPanel2Timetable("TEACHER", teacher);
                    frame.setFooterText("Timetable for TEACHER: " + teacher + " loaded.");
                }
            }
        });

        Border titledRoom = BorderFactory.createTitledBorder(etched, "ROOM:");
        roomComboBox.setBorder(titledRoom);
        roomComboBox.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                String room = (String) roomComboBox.getSelectedItem();
                if (room.charAt(0) == '-') {
                    frame.setFooterText("Select appropriate option.");
                } else//particularTimetable()
                {
                    sectionComboBox.setSelectedIndex(0);
                    teacherComboBox.setSelectedIndex(0);
                    frame.setFooterText("Loading... Please Wait");
                    frame.repaintPanel2Timetable("ROOM", room);
                    frame.setFooterText("Timetable for ROOM: " + room + " loaded.");
                }
            }
        });
        JPanel chooseTimetableOption = new JPanel();
        chooseTimetableOption.add(sectionComboBox);
        chooseTimetableOption.add(teacherComboBox);
        chooseTimetableOption.add(roomComboBox);

//contents of center border : 11x6 array
        particularTimetable = new ParticularTimetable();


//contents of south border :
        JButton backButton = new JButton("BACK");
        backButton.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                sectionComboBox.setSelectedIndex(0);
                roomComboBox.setSelectedIndex(0);
                teacherComboBox.setSelectedIndex(0);
                frame.actionBackPanel2();
            }
        });
        JButton exitButton = new JButton("EXIT");
        exitButton.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        JPanel exitPanel = new JPanel();
        exitPanel.add(backButton);
        exitPanel.add(exitButton);

        this.setLayout(new BorderLayout());
        this.add(chooseTimetableOption, BorderLayout.NORTH);
        //scrollPane.add(particularTimetable);
        //this.add(scrollPane = new JScrollPane(particularTimetable), BorderLayout.CENTER);
        centerPanel.add(particularTimetable);
        this.add(scrollPane, BorderLayout.CENTER);
        this.add(exitPanel, BorderLayout.SOUTH);
    }
    void repaintParticularTimetable(){
        particularTimetable.validate();
    }
    //JScrollPane scrollPane = new JScrollPane();
    ParticularTimetable particularTimetable;
    JPanel centerPanel = new JPanel();
    //JScrollPane scrollPane;
    JScrollPane scrollPane = new JScrollPane(centerPanel);
}


