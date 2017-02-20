'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''

from Repositories.Repository import GenericRepository

class CarRepository(GenericRepository):
    
    def __init__(self):
        
        super().__init__()
    
    def find_by_id(self, id_car):

        for obj in self._storage:
            if obj.id_car == id_car:
                return obj
            
        return None
    
    def delete(self, id_car):
        
        for obj in self._storage:
            if obj.id_car == id_car:
                self._storage.remove(obj)
                return obj
        
        raise KeyError("Object does not exist!")
        
    def add(self, car):
        
        if car in self._storage:
            raise KeyError("That car already exists!")
        
        self._storage.append(car)