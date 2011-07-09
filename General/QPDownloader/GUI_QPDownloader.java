/*
 * GUI_QPDownloader.java
 *
 */

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Component;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import javax.swing.JFrame;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.JScrollPane;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.AbstractButton;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableCellRenderer;
import java.util.Vector;
import java.util.ArrayList;

class CheckBoxRenderer implements TableCellRenderer, ItemListener {
    public CheckBoxRenderer() {
    }
	
      public void itemStateChanged(ItemEvent itemEvent) {
        AbstractButton abstractButton = (AbstractButton)itemEvent.getSource();
        int state = itemEvent.getStateChange();
        if (state == ItemEvent.SELECTED) {
			//cb.setSelected(!cb.isSelected());
			System.out.println("Checkbox change");
        }
	  }
    
	public Component getTableCellRendererComponent(
                            JTable table, Object ob,
                            boolean isSelected, boolean hasFocus,
                            int row, int column) {
		cb = (JCheckBox)ob;
        if(cb.getText().equals("")){//if label is ""
			cb.setEnabled(false);
		}
		cb.addItemListener(this);
        return cb;
    }
	JCheckBox cb;
}

public class GUI_QPDownloader extends JFrame{
    JButton dl_btn = new JButton("Download Selected");
	JTable table;
	
    public GUI_QPDownloader(String name) {
        super(name);
        //setResizable(false);
    }

    public void addComponentsToPane(final Container pane) {
		final QPDownloader qpdown = new QPDownloader();
		final Object[] columnNames = new String[qpdown.seasonPagesInfo.size()];
		int i=-1;
		for(SeasonPage sp: qpdown.seasonPagesInfo){
			columnNames[++i] = sp.toString();
		}

		System.out.println(SeasonPage.courses.size()+" "+qpdown.seasonPagesInfo.size());
		final Object[][] data = new JCheckBox[SeasonPage.courses.size()][qpdown.seasonPagesInfo.size()];
		final boolean[][] editable = new boolean[SeasonPage.courses.size()][qpdown.seasonPagesInfo.size()];
		int r=-1;
		for(String course: SeasonPage.courses){//for each course or row
			int c = -1;	++r;
			//System.out.println(course);
			for(SeasonPage season: qpdown.seasonPagesInfo){//for each season or col
				//if course  exits in season.coursesInfo.name then add JCheckBox
				boolean exists = false;
				for(CourseInfo ci: season.coursesInfo){
					if((ci.name).equals(course)){
						exists = true;
						break;
					}
				}
				if(exists){
					data[r][++c]=new JCheckBox(course, false);
					editable[r][c] = true;
				}else{
					data[r][++c]=new JCheckBox("", false);
					editable[r][c] = false;
				}
			}
		}

System.out.println((new JCheckBox()).getClass().toString() + " " + data[0][0].getClass().toString());
		final ArrayList v = new ArrayList(SeasonPage.courses);
		table = new JTable(){
			public TableCellRenderer getCellRenderer(int row, int column) {
				return new CheckBoxRenderer();
			}
		};
		table.setModel(new DefaultTableModel(data, columnNames){
			public boolean isCellEditable(int r, int c) {
				return editable[r][c];
			}
			public Class getColumnClass(int columnIndex){
				return Boolean.class;//(new JCheckBox()).getClass();
			}
			public Object getValueAt(int row, int col){
				return data[row][col];
			}
			public void setValueAt(Object value, int row, int col)
			{
				/*data[row][col] = (JCheckBox)()value;
				if(editable[row][col])
					((JCheckBox)data[row][col]).setSelected(!(((JCheckBox)data[row][col]).isSelected()));*/
				((JCheckBox)data[row][col]).setSelected((Boolean)value);
				fireTableCellUpdated(row, col);
			}



		});
		table.setFillsViewportHeight(true);
		
		//controls
        JPanel controls = new JPanel();
		dl_btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
				//do stuff
            }
        });
        controls.add(dl_btn);
		
		pane.setLayout(new BorderLayout());
        pane.add(table.getTableHeader(), BorderLayout.PAGE_START);
        pane.add(new JScrollPane(table), BorderLayout.CENTER);
        pane.add(controls, BorderLayout.SOUTH);
    }

	public static void main(String[] args){
        /* Use an appropriate Look and Feel */
        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            //UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
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