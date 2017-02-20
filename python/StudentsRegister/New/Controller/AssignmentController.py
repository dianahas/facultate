'''
Created on Nov 25, 2015

@author: Daniel
'''

from Domain.Assignment import Assignment
from Controller.UndoableOperations import *

class AssignmentController:
    
    def __init__(self, undo_controller, rental_repo, assignment_repo):
        
        self.__undo_controller = undo_controller
        
        self.__rental_repo = rental_repo
        self.__assignment_repo = assignment_repo
        
        self.__undo_operations = []
        self.__redo_operations = []
        
    def add(self, id_assignment, description):
        
        assignment= Assignment(id_assignment, description)
        
        # TODO: validate
        
        self.__assignment_repo.add(assignment)
        self.__undo_operations.append(AddOperation(assignment))
        self.__undo_controller.recordUpdatedControllers([self])
        
    def update(self, id_assignment, new_description):
        
        old_assignment = self.__assignment_repo.find_by_id(id_assignment)
        new_assignment = Assignment(id_assignment, new_description)
        self.__assignment_repo.update(new_assignment)
        self.__undo_operations.append(UpdateOperation(old_assignment,new_assignment))
        self.__undo_controller.recordUpdatedControllers([self])
        

        
    def delete(self, id_assignment):
        
        parent = self.__car_repo.delete(id_assignment)
        affected = self.__rental_repo.delete_by_assignment(id_assignment)
        
        self.__undo_operations.append(BatchRemoveOperation(parent, affected))
        self.__undo_controller.recordUpdatedControllers([self])
        
    def undo(self):

        if self.__undo_operations == []:
            return
    
    
        operation = self.__undo_operations.pop()
    
        # undo este implementat doar pentru stergerea in cascada!
        if isinstance(operation, BatchRemoveOperation):
            parent = operation.parent_object
            affected = operation.affected_objects
            
            self.__assignment_repo.add(parent)
            for rental in affected:
                self.__rental_repo.add(rental)
        elif isinstance(operation, AddOperation):
            
            assignment=operation.getObject()
            id=assignment.id_assignment
            self.__assignment_repo.delete(id)
                
        elif isinstance(operation, RemoveOperation):
            self.__assignment_repo.add(operation.getObject())
        else:
            self.__assignment_repo.update(operation.getOldObject())
            
                
        self.__redo_operations.append(operation)

    def redo(self):
        
        if self.__redo_operations == []:
            return
        
        operation = self.__redo_operations.pop()
        
        if isinstance(operation, BatchRemoveOperation):
            parent = operation.parent_object
            
            self.__student_repo.delete(parent.id_assignment)
            self.__rental_repo.delete_by_assignment(parent.id_assignment)  
        elif isinstance(operation, AddOperation):
          
            self.__assignment_repo.add(operation.getObject())
           
                
        elif isinstance(operation, RemoveOperation):
            assignment=operation.getObject()
            id=assignment.id_assignment
            self.__assignment_repo.delete(id)
            
        else:
            self.__assignment_repo.update(operation.getOldObject())  
            
    
        self.__undo_operations.append(operation)
    
        
        

    
    def get_all(self):
        
        return self.__assignment_repo.get_all()
        
        