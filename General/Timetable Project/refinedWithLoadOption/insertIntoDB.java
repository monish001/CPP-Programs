import java.sql.SQLException;

class insertIntoDB {

    insertIntoDB() {
    }

    static void insert(String[] session, String degree, int year) throws SQLException {
//courses
        String[] coursesList = db.getDistinctListFromDataBase("course", "id");
        boolean flag = false;
        if (coursesList.length != 0) {
            for (String str : coursesList) {
                if (str.equals(session[COURSE])) {
                    flag = true;
                }
            }
        }
        (db.stmt).executeUpdate("INSERT INTO course VALUES('" + session[COURSE] + "')");
//batches or sections
        String[] sectionsList = db.getDistinctListFromDataBase("batch", "id");
        flag = false;
        for (String str : sectionsList) {
            if (str.equals(session[SECTION])) {
                flag = true;
            }
        }
        (db.stmt).executeUpdate("INSERT INTO batch VALUES('" + session[SECTION] + "')");
//teacher
        String[] teachersList = db.getDistinctListFromDataBase("teacher", "id");
        flag = false;
        for (String str : teachersList) {
            if (str.equals(session[TEACHER])) {
                flag = true;
            }
        }
        (db.stmt).executeUpdate("INSERT INTO teacher VALUES('" + session[TEACHER] + "')");
//rooms
        String[] roomsList = db.getDistinctListFromDataBase("room", "id");
        flag = false;
        for (String str : roomsList) {
            if (str.equals(session[ROOM])) {
                flag = true;
            }
        }
        (db.stmt).executeUpdate("INSERT INTO room VALUES('" + session[ROOM] + "')");
//TIMETABLE (table tt)
        int day = 0;
        if (session[DAY].equals("Mon")) {
            day = 1;
        } else if (session[DAY].equals("Tue")) {
            day = 2;
        } else if (session[DAY].equals("Wed")) {
            day = 3;
        } else if (session[DAY].equals("Thu")) {
            day = 4;
        } else if (session[DAY].equals("Fri")) {
            day = 5;
        }
        (db.stmt).executeUpdate("INSERT INTO tt(cid, rid, tid, bid, day, period, degree, year) VALUES('" + session[COURSE] + "', '" + session[ROOM] + "', '" + session[TEACHER] + "', '" + session[SECTION] + "', " + day + ", " + session[PERIOD] + ", '" + degree + "', " + year + ")");
        (db.stmt).executeUpdate("commit");
    //con.close();
    }
    static DatabaseOperations db;
    static int COURSE = 0,  ROOM = 1,  TEACHER = 2,  SECTION = 3,  DAY = 4,  PERIOD = 5;


    static {
        db = new DatabaseOperations();
    }
}
