use pyo3::prelude::*;
use std::f64::consts;

#[pyfunction]
fn add(a: f64, b: f64) -> f64 {
    a + b
}

#[pyfunction]
fn subtract(a: f64, b: f64) -> f64 {
    a - b
}

#[pyfunction]
fn multiply(a: f64, b: f64) -> f64 {
    a * b
}

#[pyfunction]
fn divide(a: f64, b: f64) -> PyResult<f64> {
    if b == 0.0 {
        Err(pyo3::exceptions::PyZeroDivisionError::new_err("División por cero"))
    } else {
        Ok(a / b)
    }
}

#[pyfunction]
fn modulo(a: f64, b: f64) -> PyResult<f64> {
    if b == 0.0 {
        Err(pyo3::exceptions::PyZeroDivisionError::new_err("División por cero"))
    } else {
        Ok(a % b)
    }
}

#[pyfunction]
fn power(a: f64, b: f64) -> f64 {
    a.powf(b)
}

#[pyfunction]
fn sqrt(a: f64) -> PyResult<f64> {
    if a < 0.0 {
        Err(pyo3::exceptions::PyValueError::new_err("Raíz de número negativo"))
    } else {
        Ok(a.sqrt())
    }
}

#[pyfunction]
fn sin(x: f64) -> f64 {
    x.to_radians().sin()
}

#[pyfunction]
fn cos(x: f64) -> f64 {
    x.to_radians().cos()
}

#[pyfunction]
fn tan(x: f64) -> f64 {
    x.to_radians().tan()
}

#[pyfunction]
fn log(a: f64, base: f64) -> PyResult<f64> {
    if a <= 0.0 || base <= 0.0 {
        Err(pyo3::exceptions::PyValueError::new_err("Logaritmo de base o argumento no positivo"))
    } else {
        Ok(a.log(base))
    }
}

#[pyfunction]
fn ln(a: f64) -> PyResult<f64> {
    if a <= 0.0 {
        Err(pyo3::exceptions::PyValueError::new_err("Logaritmo natural de número no positivo"))
    } else {
        Ok(a.ln())
    }
}

#[pyfunction]
fn exp(a: f64) -> f64 {
    a.exp()
}

#[pyfunction]
fn deg_to_rad(degrees: f64) -> f64 {
    degrees.to_radians()
}

#[pyfunction]
fn rad_to_deg(radians: f64) -> f64 {
    radians.to_degrees()
}

#[pyfunction]
fn pi() -> f64 {
    consts::PI
}

#[pyfunction]
fn e() -> f64 {
    consts::E
}

/// Módulo Python
#[pymodule]
fn scientific_calc(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_function(wrap_pyfunction!(add, m)?)?;
    m.add_function(wrap_pyfunction!(subtract, m)?)?;
    m.add_function(wrap_pyfunction!(multiply, m)?)?;
    m.add_function(wrap_pyfunction!(divide, m)?)?;
    m.add_function(wrap_pyfunction!(modulo, m)?)?;
    m.add_function(wrap_pyfunction!(power, m)?)?;
    m.add_function(wrap_pyfunction!(sqrt, m)?)?;
    m.add_function(wrap_pyfunction!(sin, m)?)?;
    m.add_function(wrap_pyfunction!(cos, m)?)?;
    m.add_function(wrap_pyfunction!(tan, m)?)?;
    m.add_function(wrap_pyfunction!(log, m)?)?;
    m.add_function(wrap_pyfunction!(ln, m)?)?;
    m.add_function(wrap_pyfunction!(exp, m)?)?;
    m.add_function(wrap_pyfunction!(deg_to_rad, m)?)?;
    m.add_function(wrap_pyfunction!(rad_to_deg, m)?)?;
    m.add_function(wrap_pyfunction!(pi, m)?)?;
    m.add_function(wrap_pyfunction!(e, m)?)?;
    Ok(())
}

