import tkinter as tk

# Función que evalúa la expresión ingresada
def evaluate_expression():
    try:
        result = eval(entry.get())
        entry.delete(0, tk.END)
        entry.insert(tk.END, str(result))
    except Exception as e:
        entry.delete(0, tk.END)
        entry.insert(tk.END, "Error")

# Función para el evento click en los botones
def button_click(value):
    current = entry.get()
    entry.delete(0, tk.END)
    entry.insert(tk.END, current + str(value))

# Función para limpiar los datos en pantalla
def clear_entry():
    entry.delete(0, tk.END)

# Crear la ventana
window = tk.Tk()
window.title("Calculator")

# Crear el campo de ingreso de datos
entry = tk.Entry(window, width=40)
entry.grid(row=0, column=0, columnspan=5)

# Crear los botones de números
for i in range(10):
    if i == 0:
        button = tk.Button(window, text="0", width=5, command=lambda i=i: button_click(i))
        button.grid(row=4, column=0)
    else:
        button = tk.Button(window, text=str(i), width=5, command=lambda i=i: button_click(i))
        button.grid(row=(i - 1) // 3 + 1, column=(i - 1) % 3)

# Crear los botones de operaciones de la tercera columna
operators1 = ["+", "-", "*", "/"]
for i, operator in enumerate(operators1):
    button = tk.Button(window, text=operator, width=5, command=lambda operator=operator: button_click(operator))
    button.grid(row=1 + i, column=3)

# Crear los botones de operaciones de la cuarta columna
operators2 = {"x^2": "**2", "x^(1/2)": "**0.5", "1/x": "**(-1)", "%": "*0.01"}
for i, k in enumerate(operators2):
    button = tk.Button(window, text=k, width=5, command=lambda operator=operators2[k]: button_click(operator))
    button.grid(row=1 + i, column=4)

# Crear botones de funciones adicionales
button_clear = tk.Button(window, text="C", width=5, command=clear_entry)
button_clear.grid(row=4, column=1)

button_equal = tk.Button(window, text="=", width=5, command=evaluate_expression)
button_equal.grid(row=4, column=2)

# Ejecutar la ventana
window.mainloop()
