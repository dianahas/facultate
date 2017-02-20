'''
Created on Nov 25, 2015

@author: Daniel
'''
class AddOperation:
    """
    Class that models an add operation 
    """
    def __init__(self, object):
        """
        Constructor for AddOperation class
        object - The object that was added
        """
        self._object = object
        
    def getObject(self):
        return self._object
    
class RemoveOperation:
    """
    Class that models a remove operation 
    """
    def __init__(self, object):
        """
        Constructor for RemoveOperation class
        object - The object that was removed
        """
        self._object = object
        
    def getObject(self):
        return self._object
        
class UpdateOperation:
    """
    Class that models an update operation 
    """
    def __init__(self, oldObject, updatedObject):
        """
        Constructor for UpdateOperation class
        oldObject - The instance before updating
        updatedObject - The instance after the update
        """
        self._oldObject = oldObject
        self._updatedObject = updatedObject
        
    def getOldObject(self):
        return self._oldObject

    def getUpdatedObject(self):
        return self._updatedObject
       
class BatchRemoveOperation:
    
    def __init__(self, parent_object, affected_objects):
        '''
        parent_object - the object that caused the batch / cascade removal
        affects_objects - the objets that were deleted because of the parent_object deletion
        '''
        self.__parent_object = parent_object
        self.__affected_objects = affected_objects
        
    @property
    def parent_object(self):
        
        return self.__parent_object
    
    @property
    def affected_objects(self):
        
        return self.__affected_objects
