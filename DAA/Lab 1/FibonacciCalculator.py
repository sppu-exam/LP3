def fibonacci_recursive(n, step_count):
    step_count[0] += 1  # Increment step count each time the function is called
    if n <= 1:
        return n
    return fibonacci_recursive(n - 1, step_count) + fibonacci_recursive(n - 2, step_count)

def fibonacci_iterative(n, step_count):
    if n <= 1:
        step_count[0] = 1
        return n

    a1, a2 = 0, 1
    step_count[0] = 1  # Initial setup count
    for i in range(2, n + 1):
        a3 = a1 + a2
        a1 = a2
        a2 = a3
        step_count[0] += 1  # Count each iteration step
    return a2

def main():
    n = int(input("Enter the Fibonacci number index to calculate: "))
    
    steps_recursion = [0]
    result_recursive = fibonacci_recursive(n, steps_recursion)
    print(f"Fibonacci Recursive Result: {result_recursive}")
    print(f"Fibonacci Recursive Steps: {steps_recursion[0]}")
    
    steps_iteration = [0]
    result_iterative = fibonacci_iterative(n, steps_iteration)
    print(f"Fibonacci Iterative Result: {result_iterative}")
    print(f"Fibonacci Iterative Steps: {steps_iteration[0]}")

if __name__ == "__main__":
    main()
