import subprocess
import pytest

# Helper function to run the command and return output
def run_convert(input_data):
    result = subprocess.run(['./convert', input_data], capture_output=True, text=True)
    return result

# Char Literals Tests
def test_char_literals():
    char_literals = ['a', 'b', 'z', 'A', 'Z']
    expected_outputs = ["char: 'a'", "char: 'b'", "char: 'z'", "char: 'A'", "char: 'Z'"]

    for char, expected_output in zip(char_literals, expected_outputs):
        result = run_convert(char)
        assert result.returncode == 0, f"Failed for {char}"
        assert expected_output in result.stdout, f"Unexpected output for {char}"

# Int Literals Tests
def test_int_literals():
    int_literals = ['42', '-42', '0']
    expected_outputs = ["int: 42", "int: -42", "int: 0"]

    for num, expected_output in zip(int_literals, expected_outputs):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

# Float Literals Tests
def test_float_literals():
    float_literals = ['0.0f', '-4.2f', '4.2f', '+inff', '-inff', 'nanf']
    expected_outputs = [
        "float: 0.0f", "float: -4.2f", "float: 4.2f", 
        "float: inff", "float: -inff", "float: nanf"
    ]
    
    for num, expected_output in zip(float_literals, expected_outputs):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

def test_float_literals_with_plus():
    float_literals = ['42f', '+42f']
    expected_outputs = ["float: 42.0f", "float: 42.0f"]

    for num, expected_output in zip(float_literals, expected_outputs):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

# Double Literals Tests
def test_double_literals():
    double_literals = ['0.0', '-4.2', '4.2', '+inf', '-inf', 'nan']
    expected_outputs = [
        "double: 0.0", "double: -4.2", "double: 4.2", 
        "double: inf", "double: -inf", "double: nan"
    ]
    
    for num, expected_output in zip(double_literals, expected_outputs):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

# Invalid Input Tests
def test_invalid_input():
    invalid_inputs = ['abc', '@!$']
    for input_data in invalid_inputs:
        result = run_convert(input_data)
        assert result.returncode == 0, f"Expected failure for {input_data}"
        assert "Error: Invalid literal" in result.stdout, f"Expected 'Error: Invalid literal' but got {result.stdout}"

# Empty Input Test
def test_empty_input():
    input_data = ''
    result = run_convert(input_data)
    assert result.returncode == 0, f"Expected failure for empty input"
    assert "Error: Empty literal" in result.stdout, f"Expected 'Error: Invalid literal' but got {result.stdout}"

# Leading Zeros in Integer Literals
def test_leading_zeros_in_integers():
    int_literals = ['042', '000042', '-042', '-00042']
    expected_outputs = ["int: 42", "int: 42", "int: -42", "int: -42"]

    for num, expected_output in zip(int_literals, expected_outputs):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

# Leading Zeros in Float Literals (precision 1)
def test_leading_zeros_in_floats():
    float_literals = ['0.05f', '0.0005f', '-0.75f']
    expected_outputs = ["float: 0.1f", "float: 0.0f", "float: -0.8f"]

    for num, expected_output in zip(float_literals, expected_outputs):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

# Exponential Notation (Scientific) (precision 1)
def test_scientific_notation():
    scientific_literals = ['1e10', '2.5e-3', '-4.5e+2']
    expected_outputs = ["double: 10000000000.0", "double: 0.0", "double: -450.0"]

    for num, expected_output in zip(scientific_literals, expected_outputs):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

# Large Input Values (precision 1)
def test_large_input_values():
    large_integers = ['2147483647', '-2147483648']
    large_floats = ['3.4e+38f', '-3.4e+38f']
    expected_outputs_int = ["int: 2147483647", "int: -2147483648"]
    expected_outputs_float = ["float: 339999995214436424907732413799364296704.0f", "float: -339999995214436424907732413799364296704.0f"]  # Rounded to 1 decimal precision

    # Test for large integers
    for num, expected_output in zip(large_integers, expected_outputs_int):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

    # Test for large floats
    for num, expected_output in zip(large_floats, expected_outputs_float):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

# Edge Cases for Double and Float (e.g., +0.0, -0.0) (precision 1)
def test_edge_case_double_float():
    edge_cases = ['+0.0', '-0.0', '0.0f', '-0.0f']
    expected_outputs = [
        "double: 0.0", "double: -0.0", "float: 0.0f", "float: -0.0f"
    ]

    for num, expected_output in zip(edge_cases, expected_outputs):
        result = run_convert(num)
        assert result.returncode == 0, f"Failed for {num}"
        assert expected_output in result.stdout, f"Unexpected output for {num}"

# Special Characters Edge Case
def test_special_characters_edge_case():
    special_chars = ['\x01', '\x7F', '\t', '\n']
    expected_outputs = [
        "Error: Invalid literal", "Error: Invalid literal", 
        "Error: Invalid literal", "Error: Invalid literal"
    ]

    for char, expected_output in zip(special_chars, expected_outputs):
        result = run_convert(char)
        assert result.returncode == 0, f"Expected failure for {char}"
        assert expected_output in result.stdout, f"Expected 'Error: Invalid literal' but got {result.stdout}"
