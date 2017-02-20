'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''

from Domain.Student import Student
from Controller.UndoableOperations import *


class StudentController:
    
    def __init__(self,undo_controller, rental_repo, student_repo):
         
        self.__undo_controller = undo_controller
        self.__rental_repo = rental_repo
        self.__student_repo = student_repo
        self.__undo_operations = []
        self.__redo_operations = []
        
    def add(self, id_student, name,group):
        
        student = Student(id_student,name,group)
        
        # TODO: validate
        
        self.__student_repo.add(student)
        self.__undo_operations.append(AddOperation(student))
        self.__undo_controller.recordUpdatedControllers([self])
        
    def update(self, id_student, new_name,new_grade):
        
        old_student = self.__student_repo.find_by_id(id_student)
        new_student = Student(id_student, new_name,new_grade)
        self.__student_repo.update(new_student)
        self.__undo_operations.append(UpdateOperation(old_student,new_student))
        self.__undo_controller.recordUpdatedControllers([self])
        
        
        
    def delete(self, id_student):
        
        
        parent = self.__student_repo.delete(id_student)
        affected = self.__rental_repo.delete_by_student(id_student)
        
        self.__undo_operations.append(BatchRemoveOperation(parent, affected))
        self.__undo_controller.recordUpdatedControllers([self])
        
    def get_all(self):
        
        return self.__student_repo.get_all()
    def undo(self):

        if self.__undo_operations == []:
            return
    
    
        operation = self.__undo_operations.pop()
    
        # undo este implementat doar pentru stergerea in cascada!
        if isinstance(operation, BatchRemoveOperation):
            parent = operation.parent_object
            affected = operation.affected_objects
            
            self.__student_repo.add(parent)
            for rental in affected:
                self.__rental_repo.add(rental)
        elif isinstance(operation, AddOperation):
            
            student=operation.getObject()
            id=student.id_student
            self.__student_repo.delete(id)
                
        elif isinstance(operation, RemoveOperation):
            self.__student_repo.add(operation.getObject())
        else:
            self.__student_repo.update(operation.getOldObject())
            
                
        self.__redo_operations.append(operation)

    def redo(self):
        
        if self.__redo_operations == []:
            return
        
        operation = self.__redo_operations.pop()
        
        if isinstance(operation, BatchRemoveOperation):
            parent = operation.parent_object
            
            self.__student_repo.delete(parent.id_car)
            self.__rental_repo.delete_by_student(parent.id_car)  
        elif isinstance(operation, AddOperation):
            '''
             self.__student_repo.delete(operation.getObject().id_student)
            '''
            self.__student_repo.add(operation.getObject())
           
                
        elif isinstance(operation, RemoveOperation):
            student=operation.getObject()
            id=student.id_student
            self.__student_repo.delete(id)
            
        else:
            self.__student_repo.update(operation.getOldObject())  
            
    
        self.__undo_operations.append(operation)
    
        
        
