import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

class DatabaseOperations {

    DatabaseOperations() {
        JDBC_Connection c = new JDBC_Connection();
        stmt = c.getStatement();
    }

    String[] getDistinctListFromDataBase(String tableName, String columnName)//select query
    {
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

    boolean execute(String query)//insert, update, delete
    {
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
