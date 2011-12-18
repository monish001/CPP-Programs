import java.awt.event.ActionEvent;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.BorderFactory;
import javax.swing.JLabel;

import javax.swing.JPanel;
import javax.swing.JComboBox;
import javax.swing.JButton;
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
