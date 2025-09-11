import React from 'react'
import '../css/navbar.css';
import '../css/footer.css';
import { Link, Outlet } from 'react-router-dom';

function Layout() {
  return (
    <>
      {/* <!--  Navbar --> */}
      <nav className="navbar navbar-expand-lg navbar-light bg-beige">
        <div className="container justify-content-center">
          <div className="d-flex align-items-center gap-3">

            {/* <!-- Logo --> */}
            <Link className="navbar-brand" to="/home">
              <img src="https://openlibrary.org/static/images/openlibrary-logo-tighter.svg" alt="Logo" />
            </Link>


            {/* <!-- Links --> */}
            <ul className="navbar-nav flex-row">
              <li className="nav-item"><Link className="nav-link" to="/mybooks">My Books</Link></li>
              <li className="nav-item dropdown">
                <Link className="nav-link dropdown-toggle" data-bs-toggle="dropdown" to="#" role="button" aria-expanded="false">Browse</Link>
                <ul className="dropdown-menu">
                  <li><Link className="dropdown-item" to="#">Subjects</Link></li>
                  <li><Link className="dropdown-item" to="#">Trending Books</Link></li>
                  <li><Link className="dropdown-item" to="#">Library Explorer</Link></li>
                  <li><Link className="dropdown-item" to="#">Lists</Link></li>
                  <li><Link className="dropdown-item" to="#">Collections</Link></li>
                  <li><Link className="dropdown-item" to="#">K-12 Student Library</Link></li>
                  <li><Link className="dropdown-item" to="#">Book Talks</Link></li>
                  <li><Link className="dropdown-item" to="#">Random Book</Link></li>
                  <li><Link className="dropdown-item" to="#">Advanced Search</Link></li>
                </ul>
              </li>
            </ul>

            {/* <!-- Search --> */}
            <form className="d-flex">
              <input className="form-control search-box" type="search" placeholder="Search" aria-label="Search" />
            </form>

            {/* <!-- Buttons --> */}
            <div className="button ms-3 d-flex">
              <Link className="btn btn-outline-primary btn-sm px-3" to="/Login">Log In</Link>
              <Link className="btn btn-primary btn-sm px-3 ms-2" to="/signup">Sign Up</Link>
            </div>

            {/* <!--Offcanvas trigger button --> */}
            <button className="btn ms-3" type="button" data-bs-toggle="offcanvas" data-bs-target="#offcanvasRight">
              <span className="navbar-toggler-icon mb-2 "></span>
            </button>
          </div>
        </div>
      </nav>

      {/* <!-- Offcanvas Right Sidebar --> */}

      <div className="offcanvas offcanvas-end" style={{ backgroundColor: "#d6d2bd" }} tabindex="-1" id="offcanvasRight">
        <div className="offcanvas-header border-bottom">
          <h5 className="offcanvas-title fw-bold">My Open Library</h5>
          <button type="button" className="btn-close" data-bs-dismiss="offcanvas"></button>
        </div>
        <div className="offcanvas-body">
          <div className="mb-3 d-flex gap-2">
            <Link className="btn btn-outline-primary flex-fill" to="/login">Log In</Link>
            <Link className="btn btn-primary flex-fill" to="/signup">Sign Up</Link>
          </div>

          {/* <!-- Browse Section --> */}
          <h6 className="fw-bold mt-4">Browse</h6>
          <ul className="list-unstyled">
            <li><Link className="dropdown-item" to="#">Subjects</Link></li>
            <li><Link className="dropdown-item" to="#">Trending</Link></li>
            <li><Link className="dropdown-item" to="#">Library Explorer</Link></li>
            <li><Link className="dropdown-item" to="#">Lists</Link></li>
            <li><Link className="dropdown-item" to="#">Collections</Link></li>
            <li><Link className="dropdown-item" to="#">K-12 Student Library</Link></li>
            <li><Link className="dropdown-item" to="#">Book Talks</Link></li>
            <li><Link className="dropdown-item" to="#">Random Book</Link></li>
            <li><Link className="dropdown-item" to="#">Advanced Search</Link></li>
          </ul>

          {/* <!-- Contribute Section --> */}
          <h6 className="fw-bold mt-4">Contribute</h6>
          <ul className="list-unstyled">
            <li><Link className="dropdown-item" to="#">Add a Book</Link></li>
            <li><Link className="dropdown-item" to="#">Recent Community Edits</Link></li>
          </ul>

          {/* <!-- Resources Section --> */}
          <h6 className="fw-bold mt-4">Resources</h6>
          <ul className="list-unstyled">
            <li><Link className="dropdown-item" to="#">Help & Support</Link></li>
            <li><Link className="dropdown-item" to="#">Developer Center</Link></li>
            <li><Link className="dropdown-item" to="#">Librarians Portal</Link></li>
          </ul>
        </div>
      </div>

      {/* <Outlet /> */}
      <Outlet />


      {/* <!-- Footer --> */}
      <footer>
        <div className="container">
          <div className="row">
            {/* <!-- Open Library --> */}
            <div className="col-6 col-md-3">
              <h6>Open Library</h6>
              <Link to="#">Vision</Link>
              <Link to="#">Volunteer</Link>
              <Link to="#">Partner With Us</Link>
              <Link to="#">Careers</Link>
              <Link to="#">Blog</Link>
              <Link to="#">Terms of Service</Link>
              <Link to="#">Donate</Link>
            </div>

            {/* <!-- Discover --> */}
            <div className="col-6 col-md-3">
              <h6>Discover</h6>
              <Link to="#">Home</Link>
              <Link to="#">Books</Link>
              <Link to="#">Authors</Link>
              <Link to="#">Subjects</Link>
              <Link to="#">Collections</Link>
              <Link to="#">Advanced Search</Link>
              <Link to="#">Return to Top</Link>
            </div>

            {/* <!-- Develop --> */}
            <div className="col-6 col-md-3">
              <h6>Develop</h6>
              <Link to="#">Developer Center</Link>
              <Link to="#">API Documentation</Link>
              <Link to="#">Bulk Data Dumps</Link>
              <Link to="#">Writing Bots</Link>
            </div>

            {/* <!-- Help --> */}
            <div className="col-6 col-md-3">
              <h6>Help</h6>
              <Link to="#">Help Center</Link>
              <Link to="#">Contact Us</Link>
              <Link to="#">Suggesting Edits</Link>
              <Link to="#">Add a Book</Link>
              <Link to="#">Release Notes</Link>
              <div className="footer-icons mt-2">
                <Link to="#"><i className="bi bi-twitter-x"></i></Link>
                <Link to="#"><i className="bi bi-github"></i></Link>
              </div>
            </div>
          </div>
        </div>
      </footer>
    </>
  )
}

export default Layout
