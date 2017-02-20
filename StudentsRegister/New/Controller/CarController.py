'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''
from Domain.Car import Car
from Controller.UndoableOperations import BatchRemoveOperation

class CarController:
    
    def __init__(self, undo_controller, rental_repo, car_repo):
        
        self.__undo_controller = undo_controller
        
        self.__rental_repo = rental_repo
        self.__car_repo = car_repo
        
        self.__undo_operations = []
        self.__redo_operations = []
        
    def add(self, id_client, name):
        
        car = Car(id_client, name)
        
        # TODO: validate
        
        self.__car_repo.add(car)
        
    def update(self, id_car, new_name):
        
        new_car = Car(id_car, new_name)
        
        self.__car_repo.update(new_car)
        
    def delete(self, id_car):
        
        parent = self.__car_repo.delete(id_car)
        affected = self.__rental_repo.delete_by_car(id_car)
        
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
            
            self.__car_repo.add(parent)
            for rental in affected:
                self.__rental_repo.add(rental)
                
        self.__redo_operations.append(operation)

    def redo(self):
        
        if self.__redo_operations == []:
            return
        
        operation = self.__redo_operations.pop()
        
        if isinstance(operation, BatchRemoveOperation):
            parent = operation.parent_object
            
            self.__car_repo.delete(parent.id_car)
            self.__rental_repo.delete_by_car(parent.id_car)        
    
        self.__undo_operations.append(operation)
    
    def get_all(self):
        
        return self.__car_repo.get_all()
        
        