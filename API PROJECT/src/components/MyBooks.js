import React from 'react'
import "../css/myBooks.css";
import { Link } from 'react-router-dom';
import Navbar from './Navbar';
import Footer from './Footer';

function MyBooks() {
    return (
        <>
            <Navbar />
            <div className="main-wrapper">
                <div className="content-box">
                    <div className="container">
                        <div className="row vh-100">
                            {/* <!-- Sidebar --> */}
                            <div className="col-md-3 bg-light p-3 sidebar">
                                <h5 className="fw-bold">DARSHAN_LAPTOP</h5>
                                <ul className="list-unstyled">
                                    <li><Link to="#" className="nav-link">My Loans</Link></li>
                                    <li><Link to="#" className="nav-link">Loan History</Link></li>
                                    <li><Link to="#" className="nav-link">My Feed</Link></li>
                                </ul>

                                <hr />

                                <div className="mb-2 fw-bold">2025 READING GOAL</div>
                                <Link to="#" className="btn btn-outline-primary btn-sm mb-3">Set 2025 reading goal</Link>
                                <hr />
                                <div className="mb-2 fw-bold">READING LOG</div>
                                <ul className="list-unstyled" >
                                    <li><Link to="#" className="nav-link">Currently Reading <span className="text-muted float-end">0</span></Link></li>
                                    <li><Link to="#" className="nav-link">Want to Read <span className="text-muted float-end">0</span></Link></li>
                                    <li><Link to="#" className="nav-link">Already Read <span className="text-muted float-end">0</span></Link></li>
                                    <hr />
                                    <li><Link to="#" className="nav-link">My Notes</Link></li>
                                    <li><Link to="#" className="nav-link">My Reviews</Link></li>
                                    <hr />
                                    <li><Link to="#" className="nav-link">My Reading Stats</Link></li>
                                    <li><Link to="#" className="nav-link">Import & Export Options</Link></li>
                                </ul>

                                <hr />

                                <div className="mb-2 fw-bold">MY LISTS <Link to="#" className="float-end small">See All</Link></div>
                                <button className="btn btn-outline-secondary btn-sm">Create a list</button>
                            </div>

                            {/* <!-- Main Content --> */}
                            <div className="col-md-9 p-4">
                                <div className="d-flex justify-content-between align-items-center">
                                    <div>
                                        <h4 className="fw-bold">darshan_laptop <span className="text-muted">› Books</span></h4>
                                    </div>
                                    <div>
                                        <span className="me-3 text-muted">0 Following | 0 Followers</span>
                                        <button className="btn btn-sm btn-outline-secondary">Share</button>
                                    </div>
                                </div>

                                <div className="mt-3 mb-3">
                                    <button className="btn btn-outline-primary btn-sm me-2">My Reading Stats</button>
                                    <button className="btn btn-outline-primary btn-sm me-2">Import & Export</button>
                                    <button className="btn btn-outline-primary btn-sm w-25 p-1">Privacy settings: Public</button>
                                </div>

                                <ul className="list-unstyled mt-4">
                                    <li><Link to="#" className="fs-5">My Loans</Link>
                                        <div className="text-muted mt-2 mb-3">No books are on this shelf</div>
                                    </li>
                                    <li className="mt-3"><Link to="#" className="fs-5">Currently Reading</Link>
                                        <div className="text-muted mt-2 mb-3">No books are on this shelf</div>
                                    </li>
                                    <li className="mt-3"><Link to="#" className="fs-5">Want to Read</Link>
                                        <div className="text-muted mt-2 mb-3">No books are on this shelf</div>
                                    </li>
                                    <li className="mt-3"><Link to="#" className="fs-5">Already Read</Link>
                                        <div className="text-muted mt-2 mb-3">No books are on this shelf</div>
                                    </li>
                                    <li className="mt-3"><Link to="#" className="fs-5">My Lists (0)</Link>
                                        <div className="text-muted mt-2 mb-3">You have no lists.</div>
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <Footer />
        </>
    );
}

export default MyBooks
