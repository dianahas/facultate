'''
Created on Nov 25, 2015

@author: Daniel
'''
class UndoController:
    """
    This class controls the undo/redo operations over all application controllers.
    It is required so that we have a record of which controller must perform each undo/redo operation. 
    """
    def __init__(self):
        self.__undo_operations = []
        self.__redo_operations = []

        
    def recordUpdatedControllers(self, controllers):
        """
        Every time an application controller records an operation with support for undo/redo it must call this method
        controllers - A list of controllers that can undo/redo the operation. 
        In case an operation involves multiple distinct controllers, this is where they all have to be provided 
        """
        self.__undo_operations.append(controllers)
        self.__redo_operations.clear()
    
    def undo(self):
        """
        Undo the last performed operation by any application controller. 
        """
        
        if self.__undo_operations == []:
            return
        
        for controller in self.__undo_operations[-1]:
            controller.undo()
            
        self.__redo_operations.append(self.__undo_operations.pop())
    
    def redo(self):
        """
        Redo the last performed operation by any application controller. 
        """
        
        if self.__redo_operations == []:
            return
        
        for controller in self.__redo_operations[-1]:
            controller.redo()
            
        self.__undo_operations.append(self.__redo_operations.pop())

        return True
