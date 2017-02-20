import unittest
from Domain.Discipline import Discipline
from Domain.Exceptions import DisciplineException
from Repository.DisciplineRepository import DisciplineRepository
from Controller.DisciplineController import DisciplineController
from Domain.Student import Student
from Domain.Exceptions import StudentException
from Repository.StudentRepository import StudentRepository
from Controller.StudentController import StudentController
from Repository.GradeRepository import GradeRepository
from Controller.UndoController import UndoController

class DisciplineControllerTestCase(unittest.TestCase):
    '''
    unit test for DisciplineController
    '''
    def setUp(self):
        disRepo = DisciplineRepository()
        graRepo = GradeRepository()
        undoCtrl = UndoController()
        self.ctrl = DisciplineController(disRepo, graRepo, undoCtrl) 
        
        d1 = Discipline("1", "1")
        d2 = Discipline("2", "2")
        
        self.ctrl.addDiscipline(d1)
        self.ctrl.addDiscipline(d2)
        
    def testAddDiscipline(self):
        d = Discipline("3", "3")
        self.ctrl.addDiscipline(d)
        self.assertEqual(len(self.ctrl), 3)
        
        self.assertRaises(DisciplineException, self.ctrl.addDiscipline, d)
        
    def testFindDisciplineByTeacher(self):
        d = self.ctrl.findDisciplineByTeacher("2")
        self.assertEqual(d, [Discipline("2", "2")])

        d = self.ctrl.findDisciplineByTeacher("js")
        self.assertEqual(d, [])
        self.assertTrue(d == [])

    def testUpdateDiscipline(self):
        upD = Discipline("1", "3")
        self.ctrl.updateDiscipline("1","3")
        d = self.ctrl.findDisciplineByTeacher("3")
        self.assertEqual(d, [upD])

    def testRemoveDiscipline(self):
        self.ctrl.removeDiscipline("1")
        self.assertEqual(len(self.ctrl), 1)

        self.assertRaises(DisciplineException, self.ctrl.removeDiscipline, "3")

    def testUndoRedo(self):
        d = Discipline("3", "3")
        self.ctrl.addDiscipline(d)
        self.assertEqual(len(self.ctrl), 3)
        self.ctrl.undo()
        self.assertEqual(len(self.ctrl), 2)
        self.ctrl.undo()
        self.assertEqual(len(self.ctrl), 1)
        self.ctrl.redo()
        self.assertEqual(len(self.ctrl), 2)
        self.ctrl.redo()
        self.assertEqual(len(self.ctrl), 3)
        try:
            self.ctrl.redo()
            assert False
        except:
            assert True

class StudentControllerTestCase(unittest.TestCase):
    '''
    unit test for StudentController
    '''
    def setUp(self):
        stuRepo = StudentRepository()
        graRepo = GradeRepository()
        undoCtrl = UndoController()
        self.ctrl = StudentController(stuRepo, graRepo, undoCtrl) 
        
        s1 = Student(1, "1")
        s2 = Student(2, "2")
        
        self.ctrl.addStudent(s1)
        self.ctrl.addStudent(s2)
        
    def testAddStudent(self):
        s = Student(3, "3")
        self.ctrl.addStudent(s)
        self.assertEqual(len(self.ctrl), 3)
        
        self.assertRaises(StudentException, self.ctrl.addStudent, s)
        
    def testFindStudentByName(self):
        s = self.ctrl.findStudentByName("2")
        self.assertEqual(s, [Student(2, "2")])

        s = self.ctrl.findStudentByName("169")
        self.assertEqual(s, [])
        self.assertTrue(s == [])

    def testUpdateStudent(self):
        upS = Student(1, "3")
        self.ctrl.updateStudent(1,"3")
        s = self.ctrl.findStudentByName("3")
        self.assertEqual(s, [upS])

    def testRemoveStudent(self):
        self.ctrl.removeStudent(1)
        self.assertEqual(len(self.ctrl), 1)

        self.assertRaises(StudentException, self.ctrl.removeStudent, 3)

    def testUndoRedo(self):
        s = Student(3, "3")
        self.ctrl.addStudent(s)
        self.assertEqual(len(self.ctrl), 3)
        self.ctrl.undo()
        self.assertEqual(len(self.ctrl), 2)
        self.ctrl.undo()
        self.assertEqual(len(self.ctrl), 1)
        self.ctrl.redo()
        self.assertEqual(len(self.ctrl), 2)
        self.ctrl.redo()
        self.assertEqual(len(self.ctrl), 3)
        try:
            self.ctrl.redo()
            assert False
        except:
            assert True

if __name__ == '__main__':
    unittest.main(verbosity=2)
