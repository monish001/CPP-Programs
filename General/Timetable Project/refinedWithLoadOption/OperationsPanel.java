import java.awt.event.ActionEvent;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import javax.swing.JScrollPane;
import javax.swing.border.Border;
import javax.swing.BorderFactory;
import javax.swing.JTextArea;

import javax.swing.JPanel;
import javax.swing.JComboBox;
import javax.swing.JButton;
import javax.swing.ComboBoxModel;
import javax.swing.DefaultComboBoxModel;
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
                    } catch (SQLException ex) {
                        System.out.println("Error in insert action in ScheduleTimetable.java" + ex.toString());
                    }
                    frame.setFooterText(newItem + " inserted successfully");
                } else {
                    frame.setFooterText("ERROR: " + newItem + " NOT inserted.");
                }
                textArea.setText("");
            }
        });
        remove.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                String itemToDelete = (String) comboBox.getSelectedItem();
                if (!(itemToDelete.equals("-SELECT-"))) {
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

    void updateJComboBox() {
    }

    //constructing components
    ComboBoxModel anModel;// = new DefaultComboBoxModel();
    JComboBox comboBox;// = new JComboBox(anModel);
    JTextArea textArea = new JTextArea(4, 15);
    JButton insert = new JButton("INSERT");
    JButton update = new JButton("UPDATE");
    JButton remove = new JButton("REMOVE");
}
