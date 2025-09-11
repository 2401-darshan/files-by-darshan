import React from 'react'
import Navbar from './Navbar';
import Footer from './Footer';
import "../css/login.css";
import { Link } from 'react-router-dom';

function Login() {
    return (
        <>
            <Navbar />
            <div className='login-page'>
                <div className="login-container">
                    {/* <!-- Left Info Section --> */}
                    <div className="login-left">
                        <h2>Log In</h2>
                        <p>
                            Please Log in to use your free Open Library Account to access your account and borrow digital books
                        </p>
                    </div>

                    {/* <!-- Right Form Section --> */}
                    <div className="login-right">
                        {/* <!-- Google Sign In --> */}
                        <button className="btn btn-google w-100 ms-1 d-flex align-items-center justify-content-center gap-2">
                            <img src="google.png" alt="Google" style={{width: "20px", height: "20px"}}/>
                            <span>Sign in with Google</span>
                        </button>

                        {/* <!-- Divider --> */}
                        <div className="divider my-4">OR</div>

                        <p className="small">
                            Please enter your <Link to="#">Internet archive</Link> email and password to access your Open Library account.
                        </p>

                        {/* <!-- Login Form --> */}
                        <form>
                            <div className="mb-3">
                                <label className="form-label ms-1 fw-bold">Email</label>
                                <Link to="#" className="d-block small mb-3 ms-1">Forgot your internet archive email?</Link>
                                <input type="email" className="form-control mb-4" placeholder="Email" required />
                            </div>

                            <div className="mb-3">
                                <label className="form-label ms-1 fw-bold">Password</label>
                                <Link to="#" className="d-block small ms-1 mb-3">Forgot your Password?</Link>
                                <div className="input-group">
                                    <input type="password" className="form-control" placeholder="Password" required />
                                </div>
                            </div>

                            <div className="form-check mb-3">
                                <input className="form-check-input" type="checkbox" id="rememberMe" />
                                <label className="form-check-label" for="rememberMe">Remember me</label>
                            </div>

                            <button type="submit" className="btn btn-primary w-100 ms-1">Log In</button>
                        </form>

                        <p className="mt-3 text-center small">
                            Don’t have an account? <Link to="/signup">Sign up now.</Link>
                        </p>
                    </div>
                </div>
            </div>

            <Footer />
        </>
    )
}

export default Login
