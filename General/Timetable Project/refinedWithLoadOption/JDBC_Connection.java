import java.io.IOException;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;

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
