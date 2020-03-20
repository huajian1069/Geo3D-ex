# Exercise for "GeoModelExplorer"

The implementation for exercise 2 and 3 are combined into a single project in the folder "ex2". Here are something worth to note:
- Rotation along Z axis is actually rotation along symmetric axis of detector. This is unnoticable if does not pay attention. 
- An entity is considered picked if the picking ray intersects the **bounding volume** of the entity. That means when the detector mesh is scaled up, it may interfere picking the torus mesh. 
