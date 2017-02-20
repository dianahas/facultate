'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''
from Repositories.Repository import GenericRepository
from Repositories.RentalRepository import RentalRepository
from Controller.StudentController import StudentController
from Controller.AssignmentController import AssignmentController
from Controller.RentalController import RentalController
from UI.Console import Console
from Domain.Student import Student
from Domain.Assignment import Assignment
from Repositories.StudentRepository import StudentRepository
from Repositories.AssignmentsRepository import AssignmentRepository
from Controller.UndoController import UndoController
from Domain.Rental import Rental
from Domain.RentalDTO import RentalDTO

repo_students = StudentRepository()
repo_students.add(Student("1", "student1","100"))
repo_students.add(Student("2", "student2","200"))
repo_students.add(Student("3", "student3","300"))

repo_assignments = AssignmentRepository()
repo_assignments.add(Assignment("1", "car1"))
repo_assignments.add(Assignment("2", "car2"))
repo_assignments.add(Assignment("3", "car3"))

repo_rentals = RentalRepository()
repo_rentals.add(RentalDTO("1", "1", 1))
repo_rentals.add(RentalDTO("2", "1", 2))
repo_rentals.add(RentalDTO("3", "1", 3))

ctrl_undo = UndoController()
ctrl_students = StudentController(ctrl_undo, repo_rentals, repo_students)
ctrl_assignments = AssignmentController(ctrl_undo, repo_rentals, repo_assignments)
ctrl_rentals = RentalController(repo_students, repo_assignments, repo_rentals)

ui = Console(ctrl_undo, ctrl_assignments, ctrl_students, ctrl_rentals)

ui.show()
