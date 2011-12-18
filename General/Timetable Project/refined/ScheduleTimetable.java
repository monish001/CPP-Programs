/*ScheduleTimetable.java*/
//import javax.swing.JOptionPane;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JScrollPane;
import javax.swing.border.Border;
import javax.swing.BorderFactory;
import javax.swing.UIManager;
import javax.swing.SwingUtilities;
import javax.swing.JTextField;
import javax.swing.JTextArea;
import javax.swing.JLabel;
import javax.swing.JFrame;
import javax.swing.JDialog;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JComboBox;
import javax.swing.JButton;
import javax.swing.ComboBoxModel;
import javax.swing.DefaultComboBoxModel;

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
            UIManager.setLookAndFeel(infos[2].getClassName());
        } catch (Exception ex) {
            System.out.println("UI myerror");
        }
        SwingUtilities.updateComponentTreeUI(Frame1Timetable.this);
        //this.setExtendedState(MAXIMIZED_BOTH);
        //this.setResizable(false);
        panel1Timetable = new Panel1Timetable(this);
        panel2Timetable = new Panel2Timetable(this);

        JMenu fileMenu = new JMenu("File");
        fileMenu.setMnemonic('F');
        JMenuItem exitMenuItem = fileMenu.add("Exit");
        exitMenuItem.setMnemonic('X');
        exitMenuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        JMenu helpMenu = new JMenu("Help");
        helpMenu.setMnemonic('H');
        JMenuItem aboutMenuItem = helpMenu.add("About");
        aboutMenuItem.setMnemonic('A');
        aboutMenuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                dialog.setVisible(true);
            }
        });
        JMenuItem helpMenuItem = helpMenu.add("Documentation");
        helpMenuItem.setMnemonic('H');
        helpMenuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //throw new UnsupportedOperationException("Not supported yet.");
            }
        });

        JMenuBar menuBar = new JMenuBar();
        menuBar.add(fileMenu);
        menuBar.add(helpMenu);
        this.setJMenuBar(menuBar);

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
        //(panel2Timetable.scrollPane).removeAll();
        (panel2Timetable.centerPanel).removeAll();//(panel2Timetable.particularTimetable);
        panel2Timetable.particularTimetable = new ParticularTimetable(this, tableName, value);
        //panel2Timetable.add(panel2Timetable.scrollPane = new JScrollPane(panel2Timetable.particularTimetable), BorderLayout.CENTER);
        (panel2Timetable.centerPanel).add(panel2Timetable.particularTimetable);
        this.validateTree();
        //(panel2Timetable.scrollPane).repaint();
        //(panel2Timetable.scrollPane).validate();
        //(panel2Timetable.centerPanel).validate();
        //(panel2Timetable.centerPanel).repaint();
        //(panel2Timetable.centerPanel).paintAll((panel2Timetable.particularTimetable).getGraphics());
        //this.pack();
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

class AboutDialog extends JDialog {
    public AboutDialog(JFrame owner) {
        super(owner, "About Timetable Scheduling Software", true);
        //Look and feel
        try {
            UIManager.LookAndFeelInfo[] infos = UIManager.getInstalledLookAndFeels();
            UIManager.setLookAndFeel(infos[2].getClassName());
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
    //JScrollPane scrollPane = new JScrollPane();
    ParticularTimetable particularTimetable;
    JPanel centerPanel = new JPanel();
    //JScrollPane scrollPane;
    JScrollPane scrollPane = new JScrollPane(centerPanel);
}

/*class test extends JFrame {

public static void main(String args[]) {
EventQueue.invokeLater(new Runnable() {

public void run() {
test framePage1 = new test();
framePage1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
framePage1.setTitle("Timetable Scheduling Software: Administrator Screen");

framePage1.setVisible(true);
}
});
}

test() {
getContentPane().add(new JScrollPane(new ParticularTimetable(this, "ROOM", "F101")));
pack();
}

void setFooterText(String str) {
textField.setText(str);
}
JTextField textField = new JTextField("");
}*/
class ParticularTimetable extends JPanel {
    ParticularTimetable() {
        //initialising panelGrid
        panelGrid = new JPanel(new GridLayout(5, 10));
        day = new String[]{"MON", "TUE", "WED", "THU", "FRI"};
        //adding contents to this.
        this.setLayout(new GridBagLayout());
        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 11; c++) {
                if (r == 0) {//row 0
                    if (c == 0)//row 0 & col 0
                    {
                        JLabel label = new JLabel("");
                        //label.setBorder(BorderFactory.createEtchedBorder());
                        this.add(label, new GBC(0, 0).setFill(GridBagConstraints.BOTH).setAnchor(GridBagConstraints.NORTHWEST));
                    } else //row 0 & col not 0
                    {
                        JLabel label = new JLabel("Period " + Integer.toString(c));
                        //label.setBorder(BorderFactory.createEtchedBorder());
                        this.add(label, new GBC(0, c).setAnchor(GridBagConstraints.CENTER).setIpad(75, 0).setInsets(2, 10, 2, 0));
                    }
                } else {//row 1 2 3 4 5
                    if (c == 0)//row 1 2 3 4 5 & c 0
                    {
                        JLabel label = new JLabel(day[r - 1]);
                        //label.setBorder(BorderFactory.createEtchedBorder());
                        //label.setBounds(r*10, 0, new SavedInnerBox().getPanel().getWidth(), new SavedInnerBox().getPanel().getHeight());
                        //label.setBounds(new SavedInnerBox().getPanel().getBounds());
                        //label.setSize(new SavedInnerBox().getPanel().getWidth(), new SavedInnerBox().getPanel().getHeight());
                        this.add(label, new GBC(4 * (r - 1) + 1, 0, 1, 4).setFill(GridBagConstraints.BOTH).setAnchor(GridBagConstraints.WEST).setInsets(40, 2, 50, 2));
                    } else if (c == 1 && r == 1)//row 1 and c=1
                    {
                        this.add(panelGrid, new GBC(1, 1, 10, 20).setFill(GridBagConstraints.REMAINDER));
                    } else {
                        continue;
                    }
                }
            }//for c
        }//for r
    }
    ParticularTimetable(Frame1Timetable frame, String tableName, String value) {
        this();
        this.frame = frame;
        String[] tableNames = new String[3];
        int count = 0;
        tableNames[count] = "COURSE";
        for (String str : new String[]{"BATCH", "ROOM", "TEACHER"}) {
            if (!tableName.equals(str)) {
                count++;
                //System.out.println(str + " added to tableNames[" + count + "]");
                tableNames[count] = str;
            }
        }
        for (int r = 1; r <= 5; r++) {
            for (int c = 1; c <= 10; c++) {
                ResultSet rSet = this.isEntrySaved(r, c, tableName, value, tableNames);
                try {
                    if (rSet == null || !(rSet.next())) {
                        addNotSavedInnerBox(r, c, tableName, value, tableNames);
                    } else {
                        addSavedInnerBox(r, c, rSet, tableName, value, tableNames);
                    }
                } catch (SQLException ex) {
                    System.out.println("myERROR: " + ex.toString());
                }

            }
        }
        System.out.println(value + " choosed from " + tableName);
        this.validate();
    }//constructor
    public void addNotSavedInnerBox(int d, int p, String tableName, String idName, String[] tableNames) {//give options to save

        NotSavedInnerBox box = new NotSavedInnerBox();
        (box.btn4).addActionListener(addListener(box, d, p, tableName, idName, tableNames));
        String[] available = db.getDistinctListFromDataBase(tableNames[0], "id");//why total list is used here???
        available[0] = "-Select " + tableNames[0] + "-";
        for (String str : available) {
            (box.CBox1).addItem(str);
        }
        available = findAvailList(d, p, tableNames[1]);
        for (String str : available) {
            (box.CBox2).addItem(str);
        }
        available = findAvailList(d, p, tableNames[2]);
        for (String str : available) {
            (box.CBox3).addItem(str);
        }
        panelGrid.add(box.getPanel());
    //(box.getPanel()).validate();
    }
    public void addSavedInnerBox(int d, int p, ResultSet rSet, String tableName, String idName, String[] tableNames) {
        SavedInnerBox box = new SavedInnerBox();
        (((SavedInnerBox) (box)).btn4).addActionListener(addListener(((SavedInnerBox) (box)), d, p, tableName, idName, tableNames));
        try {
            (((SavedInnerBox) (box)).btn1).setText(rSet.getString(1));
            (((SavedInnerBox) (box)).btn2).setText(rSet.getString(2));
            (((SavedInnerBox) (box)).btn3).setText(rSet.getString(3));
        } catch (SQLException se) {
            System.out.println("myERROR line 200" + se.toString());
        }
        panelGrid.add(box.getPanel());
    //(box.getPanel()).validate();
    }
    public void addNotSavedInnerBox(SavedInnerBox oldBox, int d, int p, String tableName, String idName, String[] tableNames) {//give options to save
        NotSavedInnerBox box = new NotSavedInnerBox(oldBox);
        (((NotSavedInnerBox) (box)).btn4).addActionListener(addListener(((NotSavedInnerBox) (box)), d, p, tableName, idName, tableNames));
        String[] available = db.getDistinctListFromDataBase(tableNames[0], "id");
        available[0] = "-Select " + tableNames[0] + "-";
        for (String str : available) {
            (((NotSavedInnerBox) (box)).CBox1).addItem(str);
        }
        available = findAvailList(d, p, tableNames[1]);
        for (String str : available) {
            (((NotSavedInnerBox) (box)).CBox2).addItem(str);
        }
        available = findAvailList(d, p, tableNames[2]);
        for (String str : available) {
            (((NotSavedInnerBox) (box)).CBox3).addItem(str);
        }
    //(box.getPanel()).validate();
    }
    public void addSavedInnerBox(NotSavedInnerBox oldBox, int d, int p, ResultSet rSet, String tableName, String idName, String[] tableNames) {
        SavedInnerBox box = new SavedInnerBox(oldBox);
        (((SavedInnerBox) (box)).btn4).addActionListener(addListener(((SavedInnerBox) (box)), d, p, tableName, idName, tableNames));
        try {
            (((SavedInnerBox) (box)).btn1).setText(rSet.getString(1));
            (((SavedInnerBox) (box)).btn2).setText(rSet.getString(2));
            (((SavedInnerBox) (box)).btn3).setText(rSet.getString(3));
        } catch (SQLException se) {
            System.out.println("myERROR line 200" + se.toString());
        }
    //(box.getPanel()).validate();
    }
    public ActionListener addListener(final SavedInnerBox box, final int d, final int p, final String tableName, final String idName, final String[] tableNames) {
        //when edit button is pressed in innerBox => deletes the entry and replaces SavedInnerBox with NotSavedInnerBox
        return (new ActionListener() {

            public void actionPerformed(ActionEvent event) {
                String qry = "delete from tt where " +
                        "(day = " + d + ") and (period = " + p + ") and (" + tableName.charAt(0) + "id = '" + idName + "')";
                try {
                    System.out.println("Query(delete) for edit btn: " + qry);
                    (db.stmt).executeUpdate(qry);
                    frame.setFooterText("Entry removed, you can now enter the new values..");
                } catch (SQLException err) {
                    System.out.println("Edit button " + err.toString());
                    frame.setFooterText("Try again..error in edit btn or deletion");
                }
                addNotSavedInnerBox(box, d, p, tableName, idName, tableNames);
            //.validate();//repaint(); it will be done by above called function
            }
        });
    }
    public ActionListener addListener(final NotSavedInnerBox box, final int d, final int p, final String tableName, final String idName, final String[] tableNames) {//when save button is pressed in innerBox
        return (new ActionListener() {

            public void actionPerformed(ActionEvent event) {
                if (((box.CBox1).getSelectedIndex() != 0) && ((box.CBox2).getSelectedIndex() != 0) && ((box.CBox3).getSelectedIndex() != 0)) {
                    String qry = "insert into tt(day, period, " +
                            (tableName.charAt(0)) + "id, " + (tableNames[0].charAt(0)) + "id, " + (tableNames[1].charAt(0)) + "id, " + (tableNames[2].charAt(0)) + "id) " +
                            "values(" + d + ", " + p + ", '" + idName + "', '" + ((box.CBox1).getSelectedItem()) + "', '" + ((box.CBox2).getSelectedItem()) + "', '" + ((box.CBox3).getSelectedItem()) + "')";
                    try {
                        System.out.println("Query(insert) for save btn: " + qry);
                        (db.stmt).executeUpdate(qry);
                        frame.setFooterText("Entry successfully inserted..");
                    } catch (SQLException err) {
                        System.out.println("Query(insert) for save btn: " + err.toString());
                        frame.setFooterText("Try Again.. Error in Save button or insert query");
                    }

                    //ResultSet rSet = this.isEntrySaved(d, p, tableName, idName, tableNames);

                    qry = "select " +
                            tableNames[0].charAt(0) + "id, " + (tableNames[1].charAt(0)) + "id, " + (tableNames[2].charAt(0)) + "id from tt" +
                            " where (" + tableName.charAt(0) + "id = " + "'" + idName + "') and " +
                            "(day = " + d + ") and " +
                            "(period = " + p + ")";
                    ResultSet rset = null;
                    try {
                        rset = (db.stmt).executeQuery(qry);
                        /*//c.close();
                        } catch (SQLException e) {
                        System.out.println("b.myError in isEntrySaved()" + e.toString());
                        }
                        try {*/
                        if (rset.next()) {
                            addSavedInnerBox(box, d, p, rset, tableName, idName, tableNames);
                        } else {
                            System.out.println("error : line254, rset.next() equal to false!!");
                        }
                    } catch (SQLException excp) {
                        System.out.println("myERROR : line 273" + excp.toString());
                    }
                } else {
                    frame.setFooterText("Select options from all the three lists.");
                }
            }
        });
    }
    public ResultSet isEntrySaved(int d, int p, String tableName, String idName, String[] tableNames) {// throws SQLException
        String qry = "select " + tableNames[0].charAt(0) + "id, " +
                tableNames[1].charAt(0) + "id, " +
                tableNames[2].charAt(0) + "id from tt" +
                " where (" + tableName.charAt(0) + "id = " + "'" + idName + "') and " +
                "(day = " + d + ") and " +
                "(period = " + p + ")";
        //System.out.println("Query in isEntrySaved() : "+qry);
        ResultSet rset = null;
        try {
            rset = (db.stmt).executeQuery(qry);
        //c.close();
        } catch (SQLException e) {
            System.out.println("b.myError in isEntrySaved()" + e.toString());
        }
        return (rset);
    }
    public String[] findAvailList(int d, int p, String tableName) {
        //new myFrame();
        String[] fullList = db.getDistinctListFromDataBase(tableName, "id");
        int fullNo = fullList.length;
        String[] busyList = this.initialOptions(d, p, "tt", tableName.charAt(0) + "id");
        int busyNo = busyList.length;
        String[] availList;
        int availNo = fullNo - busyNo + 1;
        if (availNo <= 1) {
            availList = null;
        } else {
            availList = new String[availNo];
            int count = 0;
            availList[0] = "-Select " + tableName + "-";
            boolean flag = true;//true means f is available
            for (String f : fullList) {
                flag = true;
                for (String b : busyList) {
                    if (b.equals(f)) {
                        flag = false;
                        break;
                    }
                }
                if (flag == true) {
                    count++;
                    if (count >= availNo) {
                        System.out.println("Page2nd.java: 380: overflow in availList of " + tableName);
                    }
                    availList[count] = f;
                }
            }
        }
        return (availList);
    }
    public String[] initialOptions(int d, int p, String tname, String cname) {//returns first item as -Select-
        int noOfRows = 0;
        String[] CBoxOptions = null;
        String qry = new String("select count(*) from " + tname + " where (day = " + d + ") and (period = " + p + ")");
        //System.out.println("Page2nd.java: line 391 : "+qry);
        ResultSet rset;
        try {
            rset = (db.stmt).executeQuery(qry);
            while (rset.next()) {
                noOfRows = rset.getInt(1);
            }

            CBoxOptions = new String[noOfRows + 1];
            qry = new String("select " + cname + " from " + tname + " where (day = " + d + ") and (period = " + p + ")");
            //System.out.println("Page2nd.java: line 402 : "+qry+"\nNo of rows = "+noOfRows+"\n");
            rset = (db.stmt).executeQuery(qry);
            CBoxOptions[0] = "--SELECT--";//"-Select "+tname+"-";//
            for (int count = 1; rset.next(); count++) {
                CBoxOptions[count] = rset.getString(1);
            }
        } catch (Exception e) {
            System.out.println("2.)Error in InitialOptions " + e.toString());
        }
        return (CBoxOptions);
    }
    DatabaseOperations db = new DatabaseOperations();
    Frame1Timetable frame;
    JPanel panelGrid;
    String[] day;
    int MON = 0, TUE = 1, WED = 2, THU = 3, FRI = 4;
}

abstract class InnerBox {
    InnerBox() {
        myPanel.setLayout(new GridLayout(4, 1));
        //myPanel.setBorder(new SoftBevelBorder(EtchedBorder.LOWERED));
        myPanel.setBorder(BorderFactory.createLoweredBevelBorder());
    }
    public JPanel getPanel() {
        return (this.myPanel);
    }
    protected JPanel myPanel = new JPanel();
}

class SavedInnerBox extends InnerBox {
    SavedInnerBox() {
        myPanel.add(btn1);
        myPanel.add(btn2);
        myPanel.add(btn3);
        myPanel.add(btn4);
    }
    SavedInnerBox(NotSavedInnerBox box) {
        this.myPanel = box.getPanel();
        (myPanel).removeAll();
        myPanel.add(btn1);
        myPanel.add(btn2);
        myPanel.add(btn3);
        myPanel.add(btn4);
        myPanel.validate();
    }
    public JLabel btn1 = new JLabel();
    public JLabel btn2 = new JLabel();
    public JLabel btn3 = new JLabel();
    public JButton btn4 = new JButton("Edit");
}

class NotSavedInnerBox extends InnerBox {
    NotSavedInnerBox() {
        myPanel.add(CBox1);
        myPanel.add(CBox2);
        myPanel.add(CBox3);
        myPanel.add(btn4);
    }
    NotSavedInnerBox(SavedInnerBox box) {
        this.myPanel = box.getPanel();
        (myPanel).removeAll();
        myPanel.add(CBox1);
        myPanel.add(CBox2);
        myPanel.add(CBox3);
        myPanel.add(btn4);
        myPanel.validate();
    }
    public JComboBox CBox1 = new JComboBox();
    public JComboBox CBox2 = new JComboBox();
    public JComboBox CBox3 = new JComboBox();
    public JButton btn4 = new JButton("Save");
}

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

class OperationsPanel extends JPanel {
    OperationsPanel(final Frame1Timetable frame, final String tableName/*for label*/, String[] list) {
        Border etched = BorderFactory.createEtchedBorder();
        if (etched == null) {
            System.out.println("etched is null");
            System.exit(0);
        }
        Border titled = BorderFactory.createTitledBorder(etched, tableName + ":");
        this.setBorder(titled);
        this.setLayout(new GridBagLayout());
        if (list == null) {
            System.out.println("list is null");
            System.exit(0);
        }
        if (tableName == null) {
            System.out.println("name given for label is null");
            System.exit(0);
        }
        final DatabaseOperations db = new DatabaseOperations();
        //contruct combo box
        anModel = new DefaultComboBoxModel(list);
        comboBox = new JComboBox(anModel);

        //construct action listeners
        update.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                String newItem = textArea.getText().toUpperCase();
                String oldItem = (String) comboBox.getSelectedItem();
                if ((!(newItem.equals(""))) && oldItem.charAt(0) != '-' && newItem.charAt(0) != '-') {
                    try {
                        (db.stmt).executeUpdate("Update " + tableName + " set id = UPPER('" + newItem + "') where id = '" + oldItem + "'");
                    } catch (SQLException ex) {
                        System.out.println("Error in update action in ScheduleTimetable.java" + ex.toString());
                    }
                    comboBox.removeItem(oldItem);
                    comboBox.addItem(newItem);
                    frame.setFooterText(oldItem + " replaced by " + newItem + " successfully");
                } else {
                    frame.setFooterText("ERROR: " + oldItem + " NOT replaced by " + newItem);
                }
                textArea.setText("");
            }
        });
        insert.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                String newItem = textArea.getText().toUpperCase();
                if ((!(newItem.equals(""))) && newItem.charAt(0) != '-') {
                    try {//values(upper('dfsdf'))
                        (db.stmt).executeUpdate("INSERT INTO " + tableName + " VALUES(UPPER('" + newItem + "'))");
                        comboBox.addItem(textArea.getText());
                        frame.setFooterText(newItem + " inserted successfully");
                    } catch (SQLException ex) {
                        System.out.println("Error in insert action in ScheduleTimetable.java" + ex.toString());
                        frame.setFooterText("ERROR: " + newItem + " NOT inserted. The user might be inserting duplicate entries.");
                    }
                } else {
                    frame.setFooterText("ERROR: " + newItem + " NOT inserted.");
                }
                textArea.setText("");
            }
        });
        remove.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                String itemToDelete = (String) comboBox.getSelectedItem();
                if (!(itemToDelete.equals("--SELECT--"))) {
                    try {
                        (db.stmt).executeUpdate("delete from " + tableName + " where id = '" + itemToDelete + "'");
                    } catch (SQLException ex) {
                        System.out.println("Error in remove action in ScheduleTimetable.java" + ex.toString());
                    }
                    comboBox.removeItem(itemToDelete);
                    frame.setFooterText(itemToDelete + " deleted successfully");
                } else {
                    frame.setFooterText(itemToDelete + " NOT deleted");
                }
            }
        });
        this.add(comboBox, new GBC(0, 0));//.setAnchor(GridBagConstraints.CENTER));
        this.add(new JScrollPane(textArea), new GBC(0, 1, 1, 3).setFill(GridBagConstraints.BOTH));
        this.add(update, new GBC(0, 4).setFill(GridBagConstraints.BOTH));
        this.add(insert, new GBC(1, 4).setFill(GridBagConstraints.BOTH));
        this.add(remove, new GBC(2, 4).setFill(GridBagConstraints.BOTH));
    }
//    void updateJComboBox() {
  //  }
    //constructing components
    ComboBoxModel anModel;// = new DefaultComboBoxModel();
    JComboBox comboBox;// = new JComboBox(anModel);
    JTextArea textArea = new JTextArea(4, 15);
    JButton insert = new JButton("INSERT");
    JButton update = new JButton("UPDATE");
    JButton remove = new JButton("REMOVE");
}

class DatabaseOperations {
    DatabaseOperations() {
        JDBC_Connection c = new JDBC_Connection();
        stmt = c.getStatement();
    }
    String[] getDistinctListFromDataBase(String tableName, String columnName){//select query
        String[] values;
        ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
        String qry = "SELECT COUNT(*) FROM (SELECT DISTINCT " + columnName + " FROM " + tableName + ")";
        try {
            rset = stmt.executeQuery(qry);
            int noOfValues = -1;
            while (rset.next()) {
                noOfValues = rset.getInt(1);
            }
            qry = "SELECT DISTINCT " + columnName + " FROM " + tableName;
            rset = stmt.executeQuery(qry);
            values = new String[noOfValues + 1];
            values[0] = "--SELECT--";
            for (int i = 1; rset.next(); ++i) {
                values[i] = rset.getString(1);
            }
            return values;
        } catch (SQLException e) {
            System.out.println("myDetail: String[] getDistinctListFromDataBase(\"" + tableName + "\", \"" + columnName + "\"+) of class DatabaseOperations" + e.toString());
            return null;
        }
    }
    boolean execute(String query){//insert, update, delete
        try {
            stmt.executeUpdate(query);
            return true;
        } catch (SQLException e) {
            System.out.println(e.toString());
            return false;
        }
    }
    Statement stmt;
}

class JDBC_Connection {
    JDBC_Connection() {
    }
    public Statement getStatement() {
        return this.getStatement("jdbc:oracle:thin:@127.0.0.1:1521:XE", "monish001", "oracle");
    }
    public Statement getStatement(String serverAddress, String Username, String Password) {
        if (serverAddress == null) {
            serverAddress = "jdbc:oracle:thin:@127.0.0.1:1521:XE";

        }
        if (Username == null) {
            Username = "monish001";

        }
        if (Password == null) {
            Password = "oracle";

        }
        Statement stmt = null;
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");//Load DB-specific JDBC driver
            Connection conn = DriverManager.getConnection(serverAddress, Username, Password);
            stmt = conn.createStatement();
        } catch (ClassNotFoundException e) {
            System.out.println("Database Driver not found");
            System.out.println(e.toString());
        } catch (Exception e) {
            System.out.println(e.toString());
        }
        return (stmt);
    }
    public static void main(String args[]) throws SQLException, IOException {
        JDBC_Connection c = new JDBC_Connection();
        Statement stmt = c.getStatement();//null, null, null);
        ResultSet rset;  // = stmt.executeQuery("select max(studentid) from student");
        String qry = new String("select * from batch");//Execute queries and/or updates
        rset = stmt.executeQuery(qry);
        while (rset.next()) {
            System.out.println(rset.getString(1));
        }
    }
}

class GBC extends GridBagConstraints {
    public GBC(int gridx, int gridy) {
        this.gridx = gridx;
        this.gridx = gridy;
    }
    public GBC(int gridx, int gridy, int gridwidth, int gridheight) {
        this.gridwidth = gridwidth;
        this.gridheight = gridheight;
        this.gridx = gridx;
        this.gridx = gridy;
    }
    public GBC setAnchor(int anchor) {
        this.anchor = anchor;
        return this;
    }
    public GBC setFill(int fill) {
        this.fill = fill;
        return this;
    }
    public GBC setInsets(int top, int left, int bottom, int right) {
        this.insets = new Insets(top, left, bottom, right);
        return this;
    }
    public GBC setIpad(int ipadx, int ipady) {
        this.ipadx = ipadx;
        this.ipady = ipady;
        return this;
    }
}